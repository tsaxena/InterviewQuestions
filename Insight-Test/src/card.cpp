/*
 * Card.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#ifndef CARD_CPP
#define CARD_CPP

#include "card.h"

Card::Card(Rank r, Suit s, bool ifu)
	: rank_(r)
	, suit_(s)
	, is_face_up_(ifu)
{}

int Card::getValue() const
{
	//if a cards is face down, its value is 0
	int value = 0;

	if (this->is_face_up_){
		//value is number showing on card
		value = this->rank_;
		// value is 10 for face cards
		if (value > 10){
			value = 10;
		}
	}
    return value;
}

void Card::flip(){
	this->is_face_up_ = !this->is_face_up_;
}


bool Card::isFaceUp(){
	return this->is_face_up_;
}


string Card::toString(){
	stringstream ss;
 	string str;
 	const string RANKS[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K"};
    const string SUITS[] = {"s", "h", "d", "c"};

    if (this->isFaceUp()){
    	ss << RANKS[this->rank_]<< SUITS[this->suit_];
    	cout << "[" << this->rank_ << "]" ;
    }else{
        ss << "xx";
    }

    str = ss.str();
    return str;
}





#endif /* CARD_CPP */
