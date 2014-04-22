//============================================================================
// Name        : Insight-Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "game.h"
using namespace std;


vector<string> getNameOfPlayers(int no_of_players){
	vector<string> player_names(no_of_players);
	for(int i = 0; i < no_of_players; i++){
		helper::inputPrompt("Enter player name");
		helper::getStringInput(player_names[i]);
	}
	return player_names;
}


int main() {
	cout << "!!!Welcome to Multi-player Console Blackjack!!!" << endl;

	/* get number of players and
	 * names of each player
	*/
	helper::inputPrompt("Enter number of players [1-7]");
	int no_of_players = helper::getNumberInput(Game::min_players, Game::max_players);
	helper::printToConsole("Enter names of players");
	vector<string> player_names = getNameOfPlayers(no_of_players);

	Game game(player_names);
	game.play();


	return 0;
}




