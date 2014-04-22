/*
 * Hand.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#ifndef HAND_CPP
#define HAND_CPP

#include "hand.h"

Hand::Hand(){
	this->cards_.reserve(5);
}

Hand::~Hand(){
	//iterate through vector, freeing all memory on the heap
	/*vector<Card*>::iterator iter = this->cards_.begin();
	for (iter = this->cards_.begin(); iter != this->cards_.end(); ++iter){
		delete *iter;
	    *iter = 0;
	}*/

	//clear vector of pointers
	this->clear();
}

void Hand::addCard(Card* pCard){
	this->cards_.push_back(pCard);
}


int Hand::getTotal() const
{
    	// if no cards in hand, return 0
    	if ( this->cards_.empty()){
        	return 0;
    	}

    	// if a first card is face down; return 0
    	if (! this->cards_[0]->isFaceUp()){
        	return 0;
    	}

    	//add up card values, treat each Ace as 1
    	int total = 0;
    	vector<Card*>::const_iterator iter;
    	for (iter = cards_.begin(); iter != cards_.end(); ++iter){
    		int card_value = (*iter)->getValue() + 1;
    		if(card_value > 10){
    			card_value = 10;
    		}
        	total += card_value;
    	}

    	//determine if hand contains an Ace
    	bool contains_ace = false;
    	for (iter = cards_.begin(); iter != cards_.end(); ++iter){
        	if ((*iter)->getValue() == Card::ACE){
        		contains_ace = true;
        	}
    	}

    	// if hand contains Ace and total is low enough, treat Ace as 11
    	//add only 10 since we've already added 1 for the Ace
    	if (contains_ace && total <= 11){
        	total += 10;
    	}

    	return total;
}

bool Hand::isEmpty(){
	return this->cards_.empty();
}

void Hand::flipCard(int index){
	return this->cards_[index]->flip();
}

void Hand::clear(){
	this->cards_.clear();
}


void Hand::showHand() const{
	vector<Card*>::const_iterator iter;
	for (iter = this->cards_.begin(); iter != this->cards_.end(); ++iter){
		helper::printToConsole("\t" + (*iter)->toString());
	}
}

void Hand::showTotal() const{
	stringstream ss;
	ss << getTotal();
	helper::printToConsole("Your total is " + ss.str()+ ". \n");
}

void Hand::showLastCard() const{
	helper::printToConsole("Your top card is " + this->cards_.back()->toString());
}


bool Hand::isBlackjack() const{
	if(this->getTotal() == 21 ){
		return true;
	}
	return false;
}


#endif /* HAND_CPP */
