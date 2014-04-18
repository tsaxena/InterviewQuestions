/*
 * deck.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */
#include "generic-player.h"
#include "deck.h"

Deck::Deck()
{
    	this->cards_.reserve(52);
    	this->populate();
}

Deck::~Deck()
{ }

void Deck::populate()
{
    	//clear();
    	// create standard deck
    	for (int suit_iter = Card::SPADES; suit_iter <= Card::CLUBS; ++suit_iter){
        	for (int rank_iter = Card::ACE; rank_iter <= Card::KING; ++rank_iter){
                	addCard(new Card(static_cast<Card::Rank>(rank_iter), static_cast<Card::Suit>(suit_iter)));
        	}
    	}

    	/*for (int i = 0; i <= 51; ++i){
    		cout << this->cards_[i]->toString();
    	}
    	cout << endl;*/
}

void Deck::shuffle()
{
    	random_shuffle(this->cards_.begin(), this->cards_.end());

    	/*cout << "after shuffle" << endl;
    	for (int i = 0; i <= 51; ++i){
    	    cout << this->cards_[i]->toString();
    	}*/
}

void Deck::deal(GenericPlayer& gp)
{
	if (!this->cards_.empty()) {
		gp.addCard(this->cards_.back());
        this->cards_.pop_back();
    }else {
        cout << "Out of cards. Unable to deal.";
    }
}

void Deck::additionalCards(GenericPlayer& gp){
    // continue to deal a card as long as generic player isn't busted and
    // wants another hit
	while(!gp.isBusted() && gp.isHitting()){
        this->deal(gp);
        gp.showHand();
	}

	if(gp.isBusted()){
		cout << gp.getName() << " busts" << endl;
	}
}




