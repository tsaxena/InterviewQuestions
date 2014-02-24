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

using namespace std;

void fizzBuzz(int f, int b, int N){
	for(int i = 1; i <= N; i++){
		if(i% f == 0){
			cout << "F";
		}
		if(i% b == 0){
			cout << "B";
		}

		if(i%f != 0 && i%b != 0){
			cout << i ;
		}
		cout << " ";
	}
	cout << endl;
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
				vector<int> values;
				stringstream line_stream(lineBuffer);
				string tmp;
				while(std::getline(line_stream, tmp, ' ')){
					int elem = atoi(tmp.c_str());
		       		//cout << "[" << elem << "]";
		       	   	values.push_back(atoi(tmp.c_str()));
		       	}

				if(values.size() == 3){
					fizzBuzz(values[0], values[1], values[2]);
		       	}else{
		       		cout << "wrong entry in the input";
		       	}
		   }
		}
	}else{
		   cout << "Unable to open file";
	}
	return 0;
}
