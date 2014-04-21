/*
 * game.h
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#ifndef GAME_H_
#define GAME_H_

#include "helper.h"
#include "player.h"
#include "dealer.h"
#include "deck.h"

class Game{

	public:
		Game(const vector<string>& names);

		~Game();

		//plays the game of blackjack
		void play();
		void start();
		void dealAdditionalCards(GenericPlayer& player);
		void deal();
		void playersTurn();
		void dealersTurn();
		void showdown();
		//bool hasQuit(Player p);

		static bool isValidNumberOfPlayers(int x);

	private:
		Deck deck_;
		Dealer dealer_;
		vector<Player> players_;
		bool stand_;
};

#endif /* GAME_H_ */
