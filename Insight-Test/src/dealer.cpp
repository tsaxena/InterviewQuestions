/*
 * dealer.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#include "dealer.h"

Dealer::Dealer(const string& name) :  GenericPlayer(name)
{ }

Dealer::~Dealer()
{ }

bool Dealer::wantToHit() const
{
	bool b = (hand.getTotal() <= 16);
	return b;
}

void Dealer::flipFirstCard(bool b)
{
	if (!(this->hand.isEmpty())){
		if(b){
			this->hand.flipCard(0);
		}
    }
}

void Dealer::wins() const{
	helper::printToConsole(this->getName() + " wins.");
}

void Dealer::busts(){
	helper::printToConsole(this->name_ + ", you bust by going over 21.");
}







