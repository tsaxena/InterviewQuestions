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
	int no_of_players = helper::getNumberInput(Game::isValidNumberOfPlayers);
	helper::printToConsole("\nEnter names of players");
	vector<string> player_names = getNameOfPlayers(no_of_players);


	helper::printToConsole("\nOK. Lets Play \n");
	Game game(player_names);
	game.play();


	return 0;
}

/*int getNumberOfPlayers(){

	 int number_of_players = 0;
	 string input = "";
	 while (true) {
	   cout << "How many players?: (Enter 1-7)" << endl ;
	   getline(cin, input);

	   stringstream ss(input);
	   if (ss >> number_of_players){
		   if(number_of_players >= 1 && number_of_players <= 7){
		   		break;
		   }
	   }
	   cout << "Invalid number, please try again" << endl;
	 }
	 return number_of_players;
}


bool playAgain(){


	string input;
	char want_play  = {0};

	while (true) {
	   cout << "Start new game ? (Y/N): ";
	   cin.clear(); cin.sync();
	   getline(cin, input);

	   if (input.length() == 1) {
	     want_play = input[0];
	     if(want_play == 'y' || want_play == 'Y' ){
	    	 return true;
	     }else if(want_play == 'n' || want_play == 'N' ){
	    	 return false;
	     }
	   }
	   cout << "Invalid character, please try again" << endl;
	}
}*/



