/*
 * abstract-player.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#include "generic-player.h"

GenericPlayer::GenericPlayer(const string &s)
: name_(s){
}

GenericPlayer::~GenericPlayer(){
}

bool GenericPlayer::isBusted() const
{
    	return (this->hand_.getTotal() > 21);
}

void GenericPlayer::showHand() const
{
	cout << this->name_ << ": "; this->hand_.show();
	cout << " (" << this->hand_.getTotal() << ")" ;
	cout << endl;
}

string GenericPlayer::getName() const
{
	return this->name_;
}

int GenericPlayer::getHandTotal() const{
	return this->hand_.getTotal();
}




