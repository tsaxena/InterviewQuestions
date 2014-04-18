/*
 * deck.h
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#ifndef DECK_H_
#define DECK_H_

#include <string>
#include <algorithm>
#include "hand.h"

class GenericPlayer;

class Deck : public Hand{

	public:
		Deck();

		virtual ~Deck();

		//create a standard deck of 52 cards
		void populate();

		//shuffle cards
		void shuffle();

		//deal one card to a hand
		void deal(GenericPlayer& gp);

		//give additional cards to an generic player
		void additionalCards(GenericPlayer& gp);
};



#endif /* DECK_H_ */
