/*
 * helper.h
 *
 *  Created on: Apr 21, 2014
 *      Author: tripti
 */

#ifndef HELPER_H_
#define HELPER_H_

#include <string>
#include <iostream>
#include <sstream>

using namespace std;
namespace helper
{

static void printToConsole(string str){
	cout << str << endl;
}

static void inputPrompt(string str){
	cout << str <<":  ";
}

static int getNumberInput(bool(*condition)(int)) __attribute__ ((unused));

static int getNumberInput(bool(*condition)(int)){
	int number = 0;
	string input = "";
	while (true) {
		getline(cin, input);
		stringstream ss(input);
		if (ss >> number){
			if(condition(number)){
			   	break;
			}
		}
		inputPrompt("Invalid number, please try again");
    }
    return number;
}

static char getCharacterInput(bool(*condition)(char)){
   string input;
   cin.clear(); cin.sync();
   while (true) {
      getline(cin, input);
      if (input.length() == 1 && condition(toupper(input[0]))){
         return toupper(input[0]);
      }
      inputPrompt("Invalid character, please try again");
   }
}

static void getStringInput(string& str){
   getline(cin, str);
}

}


#endif /* HELPER_H_ */
