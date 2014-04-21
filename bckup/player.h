/*
 * player.h
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
#include <cctype>
#include "helper.h"
#include "generic-player.h"

using namespace std;

class Player: public GenericPlayer{
public:
		Player(const string& name, int balance = 100, int bet = 1, bool play = false);

		virtual ~Player();

		//indicates whether player is hitting
		bool isHitting() const;

		//indicates initial bet
		void bets();

		//indicates initial bet
		bool isBlackjack();

		//the player wins the game
		void win();

		//the player loses the game
		void lose();

		//the player is equal with the dealer
		void push();


		/*the player quits or balance is zero */
		bool quits();

		/*get and set for balance */
		void setBalance(int x);
		int getBalance() const;

		/*get and set for before bet*/
		void setBet(int x);
		int getBet() const;

		bool getQuitStatus() const;
		void setQuitStatus(bool status);

		static bool quitOrPlay(char x);
		bool hitOrStand(char x);
		bool isValidBet(int x);

private:
		int balance_;
		int bet_;
		bool has_quit_;
};


#endif /* PLAYER_H_ */
