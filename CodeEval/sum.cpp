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

int sum(vector<int> &V){
	int sum = 0;
	for(vector<int>::iterator i = V.begin(); i != V.end(); i++){
		sum = sum + (*i);
	}
	return sum;
}

int main(int argc, char* argv[]) {
	ifstream file;
	string lineBuffer;
	file.open(argv[1]);

	if(file.is_open()){
		vector<int> values;
		while (!file.eof()){
			getline(file, lineBuffer);
			if (lineBuffer.length() == 0){
				continue; //ignore all empty lines
			}else{
				stringstream line_stream(lineBuffer);
				string tmp;
				while(std::getline(line_stream, tmp, ' ')){
			       	values.push_back(atoi(tmp.c_str()));
			    }
			}
		}
		cout << sum(values);
	}else{
		cout << "Unable to open file";
	}
	return 0;
}
