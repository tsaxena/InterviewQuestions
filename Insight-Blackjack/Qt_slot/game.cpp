#include <typeinfo>
#include "game.h"

Game::Game()
    : player_("You"){
    srand(time(0));    //seed the random number generator
    this->deck_.populate();
    this->deck_.shuffle();

}

Game::~Game(){

}


void Game::reset(){
   this->player_.hand.clear();
   this->dealer_.hand.clear();
}


void Game::start(){
   this->reset();
   this->deal();
}

void Game::deal(){

    /* all players are given two cards
     * including the dealer in round robin */
    Card* firstCard = this->deck_.getCard();
    this->player_.hand.addCard(firstCard);
    Card* secondCard = this->deck_.getCard();
    this->player_.hand.addCard(secondCard);

    emit handChanged(this->player_.hand.getCards(), false );

    firstCard = this->deck_.getCard();
    this->dealer_.hand.addCard(firstCard);
    this->dealer_.flipFirstCard(true);
    secondCard = this->deck_.getCard();
    this->dealer_.hand.addCard(secondCard);

    emit handChanged(this->dealer_.hand.getCards(), true );

    if(this->player_.hand.isBlackjack()){
        emit statusChanged(Game::PLAYER_STAND);
    }
}


void Game::hit(){ 
    /*hit player*/
    this->hitPlayer();

    if(this->player_.isBusted()){
        emit statusChanged(Game::PLAYER_BUSTED);
        /* */
        this->dealer_.flipFirstCard(true);
        emit handChanged(this->dealer_.hand.getCards(), true);
        this->showdown();
    }

    if(this->player_.hand.isBlackjack()){
        emit statusChanged(Game::PLAYER_BLACKJACK);
    }
}


void Game::stand(){
    /*reveal the dealer card*/
    this->dealer_.flipFirstCard(true);
    emit handChanged(this->dealer_.hand.getCards(), true);

    while( !this->dealer_.isBusted() && this->dealer_.wantToHit()){
        cout << "hee" << endl;
        this->hitDealer();
        if(this->dealer_.hand.isBlackjack()){
            break;
        }
    }
    this->showdown();
}


void Game::hitDealer(){
     Card* pCard = this->deck_.getCard();
     this->dealer_.hand.addCard(pCard);
     emit handChanged(this->dealer_.hand.getCards(), true);
}

void Game::hitPlayer(){
     Card* pCard = this->deck_.getCard();
     this->player_.hand.addCard(pCard);
     emit handChanged(this->player_.hand.getCards(), false);
}

void Game::showdown(){

      /* if player is busted and dealer is not */
      if(this->player_.isBusted() && !this->dealer_.isBusted()){
          this->player_.loses();
          emit statusChanged(Game::DEALER_WINS);
          emit balanceChanged(this->player_.getBalance());
          return;
      }

       /* if player is busted and dealer is not */
      if(!this->player_.isBusted() && this->dealer_.isBusted()){
          this->player_.wins();
          emit statusChanged(Game::PLAYER_WINS);
          emit balanceChanged(this->player_.getBalance());
          return;
      }

      if( this->player_.hand.getTotal() > this->dealer_.hand.getTotal() ){
          this->player_.wins();
          emit statusChanged(Game::PLAYER_WINS);
      }else if(this->player_.hand.getTotal() < this->dealer_.hand.getTotal() ){
          this->player_.loses();
          emit statusChanged(Game::DEALER_WINS);
      }else{
          this->player_.pushes();
          emit statusChanged(Game::PLAYER_PUSHES);
      }
      emit balanceChanged(this->player_.getBalance());
}






