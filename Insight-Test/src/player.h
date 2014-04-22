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
#include "generic-player.h"

using namespace std;

class Player: public GenericPlayer{
public:
		Player(const string& name, int balance = 100, int bet = 1, bool play = false);

		virtual ~Player();

		/*indicates if player wants to hit or stand
		 * true if hit
		 * false if stand*/
		bool wantToHit() const;

		/*indicates whether the player wants to quit the game
		 * true if selected quit of balance is zero
		 * false if wants to play*/
		bool wantToQuit();

		/*indicates initial bet*/
		void bets();

		/*annouces that the player has quit */
		void quits();

		/* announces that player wins the game */
		void wins();

		/*annouces that player loses the game */
		void loses();

		/*the player is equal with the dealer*/
		void pushes();

		/*annouces that player stands */
		void busts();

		void showCurrentBalance();

		/*getter */
		int  getBalance() const;
		int  getBet() const;
		bool getQuitStatus() const;


		static bool quitOrPlay(char x);
		static bool hitOrStand(char x);

private:
		int balance_;
		int bet_;
		bool has_quit_;

protected:
		void setBalance(int x);
		void setBet(int x);
		void setQuitStatus(bool status);
};


#endif /* PLAYER_H_ */
