/*
 * game.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#include "game.h"

Game::Game(const vector<string>& player_names){
	// create a vector of players from a vector of names
	vector<string>::const_iterator player_iter;
	for (player_iter = player_names.begin(); player_iter != player_names.end(); ++player_iter){
		this->players_.push_back(Player(*player_iter));
	}

	//srand(time(0));    //seed the random number generator
	this->deck_.populate();
	this->deck_.shuffle();
}

Game::~Game(){

}


void Game::gameStarted(){
	//clear all cards

	// deal initial 2 cards to everyone
	vector<Player>::iterator player_iter;
	for (int i = 0; i < 2; ++i) {
		for (player_iter = this->players_.begin(); player_iter != this->players_.end(); ++player_iter) {
	        this->deck_.deal(*player_iter);
		}
	    this->deck_.deal(this->dealer_);
	}

	// hide house's first card
	if(!Player::getHitCount()){
		this->dealer_.flipFirstCard(true);
	}


	// display everyone's hand
	this->dealer_.showHand();
	for (player_iter = this->players_.begin(); player_iter != this->players_.end(); ++player_iter) {
		(*player_iter).showHand();
	}

	cout << endl;
}

void Game::hitSelected(size_t index){
	//deal additional cards to players
	Player::setHitCount();
	this->deck_.additionalCards(this->players_[index]);
}

// Player opted to stand, House will hit if total <= 16
void Game::standSelected(size_t index){

}

void Game::setStand(bool b)
{
	this->stand_ = b;
}


bool Game::getStand()
{
	return this->stand_;
}


void Game::play(){

	this->gameStarted();

	vector<Player>::iterator player_iter;
	for (player_iter = this->players_.begin(); player_iter != this->players_.end(); ++player_iter) {
		this->deck_.additionalCards(*player_iter);
	}

	//display dealer cards
	this->dealer_.flipFirstCard(true);
	this->dealer_.showHand();
	this->deck_.additionalCards(this->dealer_);

	// if dealer is busted then all non-busted players win
	if(this->dealer_.isBusted()){
		for (player_iter = this->players_.begin(); player_iter != this->players_.end(); ++player_iter) {
			if(!(*player_iter).isBusted()){
				cout << (*player_iter).getName() << "wins !!" << endl;
			}
		}
	}else{
		//compare the closest to 21 if not all busted
		GenericPlayer *winner;
		for (player_iter = this->players_.begin(); player_iter != this->players_.end(); ++player_iter) {

			if(!(*player_iter).isBusted()){
				if( (*player_iter).getHandTotal() > this->dealer_.getHandTotal() ){
					cout << (*player_iter).getName() << " wins" << endl;
				}else if((*player_iter).getHandTotal() < this->dealer_.getHandTotal() ){
					cout << (*player_iter).getName() << " loses" << endl;
				}else{
					cout << (*player_iter).getName() << " pushes" << endl;
				}
			}
		}
	}
}




