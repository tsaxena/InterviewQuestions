/*
 * player.h
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#ifndef GENERIC_PLAYER_H_
#define GENERIC_PLAYER_H_

#include <string>
#include <vector>
#include <iostream>
#include "hand.h"
using namespace std;


class GenericPlayer{
	//friend ostream& operator<<(ostream& os, const AbstractPlayer& aAbstractPlayer);

	public:
		GenericPlayer(const string& s = "");
		virtual ~GenericPlayer();

		//
		virtual bool isHitting() const = 0;

		//add card to the hand
		virtual void addCard(Card *card_ptr);

		//
		bool isBusted() const;

		//display the hand
		void showHand() const;

		//get name
		string getName() const;

		//get hand total
		int getHandTotal() const;

		//give back all cards to deck
		void clearHand();

	protected:
		string name_;
		Hand hand_;
};

#endif /* PLAYER_H_ */
