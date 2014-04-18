//============================================================================
// Name        : Insight-Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "game.h"
using namespace std;


int main() {
	cout << "!!!Welcome to Blackjack!!!" << endl; // prints !!!Hello World!!!

	int no_of_players = 0;
	cout << "How many players? " ;
	cin >> no_of_players;
	cin.clear();

	vector<string> name_of_players(no_of_players);
	for(int i = 0; i < no_of_players; i++){
		cout << "Enter player name: ";
		cin >> name_of_players[i];
	}

	Game game(name_of_players);
	char want_play;
	while(true){
		game.play();
		cout << "Start new game ? y/n: ";
		cin >>  want_play;
		if(want_play == 'y' || want_play == 'Y' ){
			continue;
		}else{
			cout << "Goodbye Blackjack";
			break;
		}
	}
	return 0;
}
