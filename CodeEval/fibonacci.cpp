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

int fib(int n){
	if(n < 0){
		return -1;
	}
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	return fib(n-1)+ fib(n-2);
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
				stringstream line_stream(lineBuffer);
				string tmp;
				while(std::getline(line_stream, tmp, ' ')){
			       	cout << fib(atoi(tmp.c_str())) << endl;
			    }
			}
		}
	}else{
		cout << "Unable to open file";
	}
	return 0;
}
