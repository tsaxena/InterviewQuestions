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

bool Dealer::isHitting() const
{
	bool b = (hand_.getTotal() <= 16);
	return b;
}

void Dealer::flipFirstCard(bool b)
{
	if (!(this->hand_.isEmpty())){
		if(b){
			this->hand_.flipCard(0);
		}
    }
}



