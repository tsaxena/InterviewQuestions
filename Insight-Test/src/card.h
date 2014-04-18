/*
 * Card.h
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#ifndef CARD_H_
#define CARD_H_

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Card{
	public:
		enum Rank {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		               JACK, QUEEN, KING};
		enum Suit {SPADES, HEARTS, DIAMONDS, CLUBS};

	public:
		// constructor
		Card(Rank r = ACE, Suit s = CLUBS, bool ifu = true);

		//returns the value of a card, 1 - 11
		int getValue() const;

		//flips a card; if face up, becomes face down and vice versa
		void flip();

		//indicates whether the card is up
		bool isFaceUp();

		string toString();

	private:
		Rank rank_;
		Suit suit_;
		bool is_face_up_;
};


#endif /* CARD_H_ */
