/*
 * player.h
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
#include "generic-player.h"

using namespace std;

class Player: public GenericPlayer{
public:
		Player(const string& name = "");

		virtual ~Player();

		//indicates whether player is hitting
		bool isHitting() const;

		//add card to player's hand
		void addCard(Card *card_ptr);


		static void resetHitCount();
		static void setHitCount();
		static int  getHitCount();

private:
	static int hit_count_;
};


#endif /* PLAYER_H_ */
