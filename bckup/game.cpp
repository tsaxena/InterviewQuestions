/*
 * game.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#include "game.h"

bool hasQuit(Player p){
	/**/
	return p.getQuitStatus();
}

Game::Game(const vector<string>& player_names){

	/*create a vector of players from a vector of names*/
	vector<string>::const_iterator player_iter;
	for (player_iter = player_names.begin(); player_iter != player_names.end(); ++player_iter){
		this->players_.push_back(Player(*player_iter));
	}

	srand(time(0));    //seed the random number generator
	this->deck_.populate();
	this->deck_.shuffle();
}

Game::~Game(){

}

void Game::deal(){

	/* all players are given two cards
	 * including the dealer in round robin */
	vector<Player>::iterator player_iter;
	for (int i = 0; i < 2; ++i) {
		for (player_iter = this->players_.begin(); player_iter != this->players_.end(); ++player_iter) {
			player_iter->addCard( this->deck_.getCard());
		}
		this->dealer_.addCard(this->deck_.getCard());
	}



	// hide house's first card
	this->dealer_.flipFirstCard(true);

	// display everyone's hand
	this->dealer_.showHand();
	for (player_iter = this->players_.begin(); player_iter != this->players_.end(); ++player_iter) {
		player_iter->showHand();
	}
	cout << endl;
}



void Game::playersTurn(){
	// continue to deal a card as long as generic player isn't busted and
	// wants another hit
	vector<Player>::iterator player_iter;
	for (player_iter = this->players_.begin(); player_iter != this->players_.end(); ++player_iter) {
		// if it is currently blackjack then move on to next player
		if(player_iter->isBlackjack()){
			cout << player_iter->getName() << " , you have a blackjack." << endl;
			continue;
		}
		this->dealAdditionalCards((*player_iter));
		cout << endl;
	}
}

void Game::dealersTurn(){
	// display dealer cards
	this->dealer_.flipFirstCard(true);
	this->dealer_.showHand();
	this->dealAdditionalCards(this->dealer_);
}

void Game::dealAdditionalCards(GenericPlayer& player){
	while(!player.isBusted() && player.isHitting()){
		player.addCard( this->deck_.getCard());
		player.showHand();
	}

	if(player.isBusted()){
		cout << player.getName() << " busts" << endl;
	}
}


void Game::start(){

	/*clear all cards remove everyone's cards*/
	vector<Player>::iterator player_iter;
	for (player_iter = this->players_.begin(); player_iter != this->players_.end(); ++player_iter){
		player_iter->clearHand();
	}
	this->dealer_.clearHand();

	/*get who wants to play
	 * the player can decide to quit at this point
	 * if he decides to play he should have a non-zero balance*/

	for (player_iter = this->players_.begin(); player_iter != this->players_.end(); ++player_iter){
		/* check if the player has balance */
		if(!(player_iter->quits())){
			player_iter->bets();
		}else{
			helper::printToConsole(player_iter->getName() + " has quit the game. \n");
		}
	}

	/*remove all players that have decided to quit */
	 this->players_.erase( std::remove_if(this->players_.begin(),
			 	 	 	 	 	 	 	  this->players_.end(),
			 	 	 	 	 	 	 	  hasQuit), this->players_.end() );

}

void Game::showdown(){

	//if all other players busted
	vector<Player>::iterator player_iter;

	// if dealer is busted then all non-busted players win
	if(this->dealer_.isBusted()){
		for (player_iter = this->players_.begin(); player_iter != this->players_.end(); ++player_iter) {
			if(!(*player_iter).isBusted()){
				cout << (*player_iter).getName() << " wins !!" << endl;
			}
		}
	}else{
		//compare the closest to 21 if not all busted
		//GenericPlayer *winner;
		for (player_iter = this->players_.begin(); player_iter != this->players_.end(); ++player_iter) {

			if(!(*player_iter).isBusted()){
				if( player_iter->getHandTotal() > this->dealer_.getHandTotal() ){
					player_iter->win();

				}else if((*player_iter).getHandTotal() < this->dealer_.getHandTotal() ){
					player_iter->lose();
				}else{
					cout << (*player_iter).getName() << " pushes" << endl;
					player_iter->push();
				}
			}
		}
	}
}


void Game::play(){

	while(true){
		this->start();
		/* if all players have quit
		 * end the game */
		if(this->players_.size() == 0){
			helper::printToConsole("All players have quit the game. Game Over");
			break;
		}
		this->deal();
		this->playersTurn();
		this->dealersTurn();
		this->showdown();
	}
	cout << "Goodbye" << endl;
}

bool Game::isValidNumberOfPlayers(int number){
	return (number >= 1 && number <= 7);
}









