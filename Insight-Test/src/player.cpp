/*
 * player.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: tripti
 */

#include "player.h"

int Player::hit_count_ = 0;

Player::Player(const string& name)
: GenericPlayer(name){
	//cout << "I m a player";
}

Player::~Player(){

}

bool Player::isHitting() const
{
	char want_hit;
	cout << this->getName() << ", Do you want to hit ? (Y/N)";
	cin >> want_hit ;
	if(want_hit == 'Y' || want_hit == 'y'){
		return true;
	}
	return false;
}

void Player::addCard(Card *card_ptr)
{
	this->hand_.addCard(card_ptr);
}


int Player::getHitCount()
{
 	return Player::hit_count_;
}

void Player::resetHitCount()
{
 	Player::hit_count_ = 0;
}


void Player::setHitCount()
{
 	Player::hit_count_++;
}





