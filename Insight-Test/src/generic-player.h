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

		/*indicates whether a generic player wants to hit */
		virtual bool wantToHit() const = 0;

		/*get name of a generic player*/
		string getName() const;

		/* indicates whether a generic player has busted
		 * by going over 21
		 */
		bool isBusted() const;

		/*announces that the generic player busts*/
		virtual void busts() = 0;

		/*annouces that the generic player hits*/
		void hits() const;

		/*annouces that the generic player hits*/
		void stands() const;

		/*annouces player state*/
		void showState() const;

		/*announces that the player has blackjack */
		void blackjack()const;

		Hand hand;

	protected:
		string name_;

};

#endif /* PLAYER_H_ */
