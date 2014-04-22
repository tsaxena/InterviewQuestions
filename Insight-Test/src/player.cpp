/*
 * player.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#include "player.h"


Player::Player(const string& name, int balance, int bet, bool play)
: GenericPlayer(name)
, balance_(balance)
, bet_(bet)
, has_quit_(play){
}

Player::~Player(){

}

bool Player::wantToHit() const{
	helper::inputPrompt(this->getName() + ", Hit(H) or Stand(S)? ");
	char c = helper::getCharacterInput(Player::hitOrStand);
	switch(c){
        case 'H': return true;
        case 'S': return false;
	}
	return false;
}


void Player::bets(){
	helper::printToConsole(this->getName() + ", You have " + helper::toString(this->balance_) + " Dollars.");
	helper::inputPrompt("Your bet (1.." +  helper::toString(this->balance_) + ")");
	this->setBet(helper::getNumberInput(1, this->getBalance()));
}

/*if the balance is zero
 * then player is forced to quit
 * else ask player if he wants to play*/
bool Player::wantToQuit(){

	if(this->getBalance() == 0){
		return true;
	}else{
		helper::inputPrompt(this->getName() + ", Quit(Q) or Play(P)? ");
		char c = helper::getCharacterInput(Player::quitOrPlay);
		switch(c){
			case 'Q': return true;
			case 'P': return false;
		}
	}
	return false;
}


/**********************************
 * Functions for console output *
 * *******************************/

void Player::quits(){
	this->setQuitStatus(true);
	helper::printToConsole(this->getName() + " has left the game with $" +
			               helper::toString(this->getBalance())+ ".\n");
}


void Player::showCurrentBalance(){
	helper::printToConsole(this->getName() + ", your current balance is $" + helper::toString(this->getBalance()));
}


void Player::wins(){
	helper::printToConsole(this->getName() + " WINS.");
	this->setBalance(this->getBalance() + this->getBet());
	this->showCurrentBalance();
}

void Player::busts(){
	helper::printToConsole(this->name_ + ", you bust by going over 21.");
	this->loses();
}


/*the player loses the game*/
void Player::loses(){
	helper::printToConsole(this->getName() + ", you lose.");
	this->setBalance(this->getBalance()- this->getBet());
	this->showCurrentBalance();
}

/*the player pushes the game gets to keep the bet money*/
void Player::pushes(){
	helper::printToConsole(this->getName() + " pushes.");
	this->showCurrentBalance();
}


/**********************************
 * Accessor functions             *
 * ********************************/
int Player::getBalance() const{
	return this->balance_;
}

void Player::setBalance(int b){
	this->balance_ = b;
}


int Player::getBet() const{
	return this->bet_;
}


void Player::setBet(int b){
	this->bet_ = b;
}


bool Player::getQuitStatus() const{
	return this->has_quit_;
}

void Player::setQuitStatus(bool status){
	this->has_quit_ = status;
}

bool Player::quitOrPlay(char c){
	return (c == 'Q' || c =='P');
}


bool Player::hitOrStand(char c){
	return (c == 'H' || c =='S');
}













