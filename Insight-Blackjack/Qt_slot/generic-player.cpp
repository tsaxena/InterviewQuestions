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

string GenericPlayer::getStateString() const
{
    string str = "";
    ostringstream oss;
    std::vector<Card> cards = this->hand.getCards();
    std::vector<Card>::const_iterator card_iter = cards.begin();
    for(; card_iter != cards.end(); ++ card_iter){
        oss << "(" << card_iter->toString() <<") ";
    }
    oss << " " << this->hand.getTotal();
    return oss.str();
}

void GenericPlayer::stands() const{
    helper::printToConsole(this->getName() + " stands.\n");
}



