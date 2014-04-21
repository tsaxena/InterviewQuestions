/*
 * Hand.h
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <iostream>
#include "card.h"

class Hand {
	public:
		Hand();

		virtual ~Hand();

		//adds a card to the hand
		void addCard(Card* card_ptr);

		//clears hand of all cards
		void clear();

		int getTotal() const;

		void show() const;

		bool isEmpty();

		void flipCard(int index);

	protected:
		vector<Card*> cards_;
};

#endif /* HAND_H_ */
