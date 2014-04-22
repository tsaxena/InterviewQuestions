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

class Deck{

	public:
		Deck();

		virtual ~Deck();

		/*create a standard deck of 52 cards*/
		void populate();

		/*shuffle cards*/
		void shuffle();

		/*get one card from the top*/
		Card* getCard();

		/*put back one card*/
		void  putCard(Card* card_ptr);

		/*clear the deck*/
		void  clear();

	private:
		vector<Card*> cards_;
};



#endif /* DECK_H_ */
