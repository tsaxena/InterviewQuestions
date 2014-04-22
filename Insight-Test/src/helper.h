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

    static void printToConsole(string str) __attribute__ ((unused));
    static void printToConsole(string str){
        cout << str << endl;
    }

    static void inputPrompt(string str) __attribute__ ((unused));
    static void inputPrompt(string str){
       cout << str <<":  ";
    }


   static int getNumberInput(const int min, const int max) __attribute__ ((unused));
   static int getNumberInput(const int min, const int max){
      int number = 0;
      string input = "";
      while (true) {
         getline(cin, input);
         stringstream ss(input);
         if (ss >> number){
            if(number >= min && number <= max){
               break;
            }
         }
         inputPrompt("Invalid number, please try again");
      }
      printToConsole("\n");
      return number;
   }

   static char getCharacterInput(bool(*condition)(char)) __attribute__ ((unused));
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

   static void getStringInput(string& str) __attribute__ ((unused));
   static void getStringInput(string& str){
      getline(cin, str);
   }

   static string toString(int number) __attribute__ ((unused));
   static string toString(int number){
      stringstream ss;
	  ss << number;
	  return ss.str();
   }

}
#endif /* HELPER_H_ */
