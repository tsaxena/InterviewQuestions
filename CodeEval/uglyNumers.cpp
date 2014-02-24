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
#include <cstring>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <tr1/unordered_map>
#include <stack>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

//====================================================================//
//ugyly numbers

void eval(stack<int> &numStck, stack<char> &opStck){
	int a, b;
	char op;
	if(numStck.size() == 2 && opStck.size() == 1){
		 b = numStck.top(); numStck.pop();
		 a = numStck.top(); numStck.pop();
		 op = opStck.top(); opStck.pop();

		 if(op == '+'){
			 numStck.push(a + b);
		 }else if (op == '-'){
			 numStck.push(a - b);
		 }
	}
}

bool isUgly(int num){
	if(num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0){
		return true;
	}
	return false;
}

bool isUgly(string str){

	if(str.length() == 1){
		return isUgly(atoi(str.c_str()));
	}
	stack<int> numStck;
	stack<char> opStck;

	std::size_t found = str.find_first_of("+-");
	size_t start_pos = 0;

	while (found != std::string::npos){
	    string token = str.substr(start_pos, found - start_pos);

	    //1 + 12 -3
	    //get first number
	    numStck.push(atoi(token.c_str()));

	    //evaluate the stack
	    eval(numStck, opStck);

	    //push next operator
	    opStck.push(str[found]);

	    //move the pointers
	    start_pos = found + 1;
	    found=str.find_first_of("+-",found+1);
	}
	string last_token = str.substr(start_pos);
	numStck.push(atoi(last_token.c_str()));
	eval(numStck, opStck);

	int expr_val = numStck.top();
	return isUgly(expr_val);

}

bool isSolution(string &ip, size_t k){
	return( (k == ip.length()));
}



int numberOfUglyNumbers(string &ip, string &op, int k){
	if(isSolution(ip,k)){
		if(isUgly(op)){
			return 1;
		}else{
			return 0;
		}
	}
	//create candidates
	// candidate1: 1+23
	string orig(op);
	int nouc = 0;

	//make move
	op.push_back('+');
	op.append(ip.substr(k, 1));
	//backtrack
	nouc += numberOfUglyNumbers(ip, op, k+1);
	//unmake move
	op = orig;

	//make move
	op.push_back('-');
	op.append(ip.substr(k, 1));
	//backtrack
	nouc += numberOfUglyNumbers(ip, op, k+1);
	//unmake move
	op = orig;

	//make move
	op.append(ip.substr(k, 1));
	//backtrack
	nouc += numberOfUglyNumbers(ip, op, k+1);
	//unmake move
	op = orig;

	return nouc;
}



int main(int argc, char* argv[]) {
	ifstream file;
	string lineBuffer;
	file.open(argv[1]);

	if(file.is_open()){
		while (!file.eof()){
			vector<string> values;
			getline(file, lineBuffer);
			if (lineBuffer.length() == 0){
				continue; //ignore all empty lines
			}else{
				stringstream line_stream(lineBuffer);
				string tmp;
				while(std::getline(line_stream, tmp, ' ')){
			       	values.push_back(tmp);
			    }
				//cout << values[0] << endl;

				//cout << numberOfUglyNumbers(values[0], op,1) << endl;
				string ip = values[0];//"011";
				string op = ip.substr(0,1);
				cout << numberOfUglyNumbers(ip,op,1) << endl;
			}

		}

	}else{
		cout << "Unable to open file";
	}
	return 0;
}
