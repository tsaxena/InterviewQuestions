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
    	this->populate();
}

Deck::~Deck()
{
	this->clear();
}

void Deck::populate()
{
	//clear();
    // create standard deck
    for (int suit_iter = Card::SPADES; suit_iter <= Card::CLUBS; ++suit_iter){
        for (int rank_iter = Card::ACE; rank_iter <= Card::KING; ++rank_iter){
        	this->putCard(new Card(static_cast<Card::Rank>(rank_iter), static_cast<Card::Suit>(suit_iter)));
        }
    }
}

void Deck::shuffle()
{
    random_shuffle(this->cards_.begin(), this->cards_.end());

}

Card* Deck::getCard(){
	/* check cards */
	if (!this->cards_.empty()) {
        this->cards_.pop_back();
        return this->cards_.back();
    }

	cout << "Out of cards. Unable to deal.";
    return NULL;
}


void Deck::putCard(Card* card_ptr){
	this->cards_.push_back(card_ptr);
}

void Deck::clear(){
	/*iterate through vector, freeing all memory on the heap*/
	for (int card_iter = 0; card_iter <= 51; ++card_iter){
		delete this->cards_[card_iter];
	}
}





