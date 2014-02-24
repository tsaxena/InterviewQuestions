//============================================================================
// Name        : CodeEval.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <tr1/unordered_map>
#include <stack>

using namespace std;

void reverseAndCopy(string &s, int start , int end, int k){
	//reverse the whole string
	int i = start;
	int j = end;
	while(i < j){
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}

	for(int x = start; x <= end ; x++){
		s[k++] = s[x];
	}
	//cout << "[" << s <<"]"<< endl;
}
void reverseSentence(string &text) {
	int len = text.size();

	reverseAndCopy(text, 0, len-1, 0);
	int read_pos  = 0;
	int write_pos = 0;
	while (read_pos < len) {
		if (text[read_pos]!=' ') {
			int wordStart= read_pos;
			for ( ; read_pos<len && text[read_pos]!=' '; read_pos++);
			reverseAndCopy(text, wordStart, read_pos-1, write_pos);
			write_pos = write_pos + read_pos - wordStart;
			text[write_pos++]=' ';
		}
		read_pos++;
	}
	text = text.substr(0, write_pos);
}

int main(int argc, char* argv[]) {
	ifstream file;
	string lineBuffer;
	file.open(argv[1]);

	if(file.is_open()){
		while (!file.eof()){
			getline(file, lineBuffer);
			if (lineBuffer.length() == 0){
				continue; //ignore all empty lines
			}else{
				reverseSentence(lineBuffer);
				cout << lineBuffer << endl;
				//reverseSentence(s);
		   }
		}
	}else{
		   cout << "Unable to open file";
	}

	//textDollar(101);
	return 0;
}
