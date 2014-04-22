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
    return (this->hand.getTotal() > 21);
}


string GenericPlayer::getName() const
{
    return this->name_;
}


void GenericPlayer::hits() const{
    helper::printToConsole(this->getName() + " hits.");
    this->hand.showLastCard();
    this->showState();
}

void GenericPlayer::blackjack() const{
    helper::printToConsole(this->getName() + " , you have a blackjack.");
}

void GenericPlayer::showState() const
{
    helper::printToConsole(this->getName() + ", Your cards are:");
    this->hand.showHand();
    this->hand.showTotal();
}

void GenericPlayer::stands() const{
    helper::printToConsole(this->getName() + " stands.\n");
}



