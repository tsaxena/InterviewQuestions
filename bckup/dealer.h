/*
 * dealer.h
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#ifndef DEALER_H_
#define DEALER_H_

#include "generic-player.h"

class Dealer : public GenericPlayer{
public:
	Dealer(const string& name = "Dealer");

	virtual ~Dealer();

	//flips over first card
	void flipFirstCard(bool b);

	//indicates whether the dealer is hitting - will always hit on 16 or less
	virtual bool isHitting() const;

};


#endif /* DEALER_H_ */
