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
		void reset();
		void start();
		void deal();
		void hit();
		void hit(GenericPlayer& player);
		void showdown();

		static const int min_players = 1;
		static const int max_players = 7;
	private:
		Deck deck_;
		Dealer dealer_;
		vector<Player> players_;
};

#endif /* GAME_H_ */
