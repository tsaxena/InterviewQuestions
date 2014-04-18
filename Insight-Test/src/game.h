/*
 * game.h
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#ifndef GAME_H_
#define GAME_H_

#include "player.h"
#include "dealer.h"
#include "deck.h"

class Game{

	public:
		Game(const vector<string>& names);

		~Game();

		//plays the game of blackjack
		void play();
		void gameStarted();
		void hitSelected(size_t index);
		void standSelected(size_t index);
		bool getStand();
		void setStand(bool b);

	private:
		Deck deck_;
		Dealer dealer_;
		vector<Player> players_;
		bool stand_;
};

#endif /* GAME_H_ */
