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

bool Player::isHitting() const
{
	string input;
	char want_hit  = {0};

	cin.clear(); cin.sync();
	while (true) {
		cout << this->getName() << ", Hit(H) or Stand(S)? ";
		getline(cin, input);

		if (input.length() == 1) {
		     want_hit = toupper(input[0]);
		     if(want_hit == 'H' ){
		    	 return true;
		     }else if(want_hit == 'S'){
		    	 return false;
		     }
		}
		cout << "Please respond H or S " << endl;
     }
}

void Player::bets(){
	int bet = 0;
    string input = "";

	cin.clear(); cin.sync();
	cout << this->getName() << ", You have " << this->balance_ << " Dollars." << endl;
	while (true) {

		cout << "How many dollars do you want to bet? ";
		getline(cin, input);

		stringstream ss(input);
		if (ss >> bet){
			 if(bet >= 1 && bet <= this->balance_){
			   	break;
			 }
		}
		cout << "Invalid number, please try again" << endl;
	}

	cout << endl;
	this->bet_ = bet;
}


/*if the balance is zero
 * then player is forced to quit
 * else ask player if he wants to play*/
bool Player::quits(){

	if(this->getBalance() == 0){
		helper::printToConsole(this->getName() + ", You have 0 Dollars.");
		helper::printToConsole(this->getName() + " has quit the game.\n");
		return true;
	}else{
		helper::inputPrompt(this->getName() + ", Quit(Q) or Play(P)? ");
		char c = helper::getCharacterInput(Player::quitOrPlay);
		switch(c){
			case 'Q': {this->setQuitStatus(true);
			           return true;
			          }
			case 'P': return false;
		}
		/*while (true) {
			string input = "";
			char want_hit  = {0};


			getline(cin, input);

			if (input.length() == 1) {
				want_hit = toupper(input[0]);
				if(want_hit == 'Q' ){
					cout << this->getName() << " has quit the game." << endl;
					this->has_quit_ = true;
					return true;
				}else if(want_hit == 'P'){
					return false;
				}
			}
			cout << "Please respond Q or P " << endl;
		}*/
	}
	return false;
}


void Player::win(){
	cout << this->getName() << " wins." << endl;
	this->setBalance(this->bet_);
}

//the player loses the game
void Player::lose(){
	cout << this->getName() << " loses." << endl;
	this->setBalance(- this->bet_);
}

//the player pushes the game
// gets to keep the bet money
void Player::push(){
	cout << this->getName() << " pushes." << endl;
}


bool Player::isBlackjack(){
	if(this->getHandTotal() == 21 ){
		return true;
	}
	return false;
}


int Player::getBalance() const{
	return this->balance_;
}

void Player::setBalance(int b){
	this->balance_ = b;
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











