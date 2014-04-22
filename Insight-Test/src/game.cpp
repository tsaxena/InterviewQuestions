/*
 * game.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#include "game.h"

bool hasQuit(Player p){
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

void Game::reset(){
	/*clear all cards remove everyone's cards*/
	vector<Player>::iterator player_iter;
	for (player_iter = this->players_.begin(); player_iter != this->players_.end(); ++player_iter){
		player_iter->hand.clear();
	}
	this->dealer_.hand.clear();
}


void Game::start(){

	this->reset();
	/*get the bets of all players who wants to play*/
	vector<Player>::iterator player_iterator;
	for (player_iterator = this->players_.begin(); player_iterator != this->players_.end(); ++player_iterator){
		/* check if the player has balance */
		if(!(player_iterator->wantToQuit())){
			player_iterator->bets();
		}else{
			player_iterator->quits();
		}
	}

	/*remove all players that have decided to quit */
	 this->players_.erase( std::remove_if(this->players_.begin(),
			 	 	 	 	 	 	 	  this->players_.end(),
			 	 	 	 	 	 	 	  hasQuit), this->players_.end() );

}

void Game::deal(){

	/* all players are given two cards
	 * including the dealer in round robin */
	vector<Player>::iterator player_iterator;
	for (int i = 0; i < 2; ++i) {
		for (player_iterator = this->players_.begin();
			 player_iterator != this->players_.end();
			 ++player_iterator) {
			player_iterator->hand.addCard(this->deck_.getCard());
		}
		this->dealer_.hand.addCard(this->deck_.getCard());
	}

	// hide house's first card
	this->dealer_.flipFirstCard(true);

	// display everyone's hand
	for (player_iterator = this->players_.begin();
		 player_iterator != this->players_.end();
		 ++player_iterator) {
		player_iterator->showState();
	}

	this->dealer_.showState();
	cout << endl;
}

void Game::hit(GenericPlayer& player){
	/*if it is currently blackjack */
    if(player.hand.isBlackjack()){
	    player.blackjack();
	    return;
    }

    while(!player.isBusted() && player.wantToHit()){
        player.hand.addCard( this->deck_.getCard());
        player.hits();
        if(player.hand.isBlackjack()){
        	break;
        }
    }

	if(player.isBusted()){
		player.busts();
	}else{
		player.stands();
	}
}

void Game::hit(){
	/*continue to deal a card as player is not busted
	 * and wants to hit
	 */
    vector<Player>::iterator player_iterator;
    for (player_iterator = this->players_.begin();
    		player_iterator != this->players_.end();
    		++player_iterator) {
        this->hit(*player_iterator);
    }

    /* dealers turn */
    this->dealer_.flipFirstCard(true);
    this->dealer_.showState();

    /*Hit dealer only if there are
     * non-busted players */
    bool all_busted = true;
    for (player_iterator = this->players_.begin();
            player_iterator != this->players_.end();
            ++player_iterator) {
        all_busted = all_busted && player_iterator->isBusted();
    }

    if(!all_busted){
    	this->hit(this->dealer_);
    }
}


void Game::showdown(){

	 /*CASE 1: all players have busted */
	 vector<Player>::iterator player_iterator;
	 bool all_busted = true;
	 for (player_iterator = this->players_.begin();
	       player_iterator != this->players_.end();
	       ++player_iterator) {
	     all_busted = all_busted && player_iterator->isBusted();
	  }

	  if(all_busted && !this->dealer_.isBusted()){
	     this->dealer_.wins();
	     return;
	  }


	/*CASE 1: dealer has busted but there are non-busted players */
	/*if dealer is busted then all non-busted players win*/
	if(this->dealer_.isBusted()){
		for (player_iterator = this->players_.begin();
			 player_iterator != this->players_.end();
			 ++player_iterator) {
			if(!(player_iterator->isBusted())){
				player_iterator->wins();
			}
		}
		return;
	}


	/* CASE 3: Dealer has not busted
	 * and there are non busted players
	 */
    for (player_iterator = this->players_.begin();
            player_iterator != this->players_.end();
    		++player_iterator) {

        if(!(player_iterator->isBusted())){
            if( player_iterator->hand.getTotal() > this->dealer_.hand.getTotal() ){
            	player_iterator->wins();
            }else if(player_iterator->hand.getTotal() < this->dealer_.hand.getTotal() ){
                player_iterator->loses();
            }else{
                player_iterator->pushes();
			}
		}
	}
}


void Game::play(){

	helper::printToConsole("\nOK. Lets Play \n");
	while(true){

		this->start();
		/* if all players have quit
		 * end the game */
		if(this->players_.size() == 0){
			helper::printToConsole("All players have quit the game. Game Over");
			break;
		}
		this->deal();
		this->hit();
		this->showdown();

		helper::printToConsole("\nOK. Lets Play Another Hand \n");
	}
	cout << "Goodbye" << endl;
}










