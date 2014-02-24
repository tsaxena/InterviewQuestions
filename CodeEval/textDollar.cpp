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

string numberToString(int N, tr1::unordered_map<int, string> &my_map){
	string s;
	int x = N/100;

	if(x != 0){
		tr1::unordered_map<int, string>::iterator i = my_map.find(x);
		if(i != my_map.end()){
			s.append((*i).second);
		}
		s.append("Hundred");
	}

	int y = N%100;
	if(y != 0){
		int a = y / 10;
		int b = y % 10;

		if(a == 1){
			//find y in hash map
			tr1::unordered_map<int, string>::iterator j = my_map.find(y);
			s.append(((*j).second));
			return s;
		}
		// find a
		tr1::unordered_map<int, string>::iterator ai = my_map.find(a*10);
		if(ai != my_map.end()){
			s.append((*ai).second);
		}

		// find b
		tr1::unordered_map<int, string>::iterator bi = my_map.find(b);
		if(bi != my_map.end()){
			s.append((*bi).second);
		}
	}
	return s;
}

void textDollar(int N){

	if(N < 0){
		cout << "Invalid Input";
		return;
	}

	if(N == 0){
		cout << "ZeroDollars";
		return;
	}
	tr1::unordered_map<int, string> my_map;
	my_map.insert(std::make_pair(1, "One"));
	my_map.insert(std::make_pair(2, "Two"));
	my_map.insert(std::make_pair(3, "Three"));
	my_map.insert(std::make_pair(4, "Four"));
	my_map.insert(std::make_pair(5, "Five"));
	my_map.insert(std::make_pair(6, "Six"));
	my_map.insert(std::make_pair(7, "Seven"));
	my_map.insert(std::make_pair(8, "Eight"));
	my_map.insert(std::make_pair(9, "Nine"));
	my_map.insert(std::make_pair(10, "Ten"));
	my_map.insert(std::make_pair(11, "Eleven"));
	my_map.insert(std::make_pair(12, "Twelve"));
	my_map.insert(std::make_pair(13, "Thirteen"));
	my_map.insert(std::make_pair(14, "Fourteen"));
	my_map.insert(std::make_pair(15, "Fifteen"));
	my_map.insert(std::make_pair(16, "Sixteen"));
	my_map.insert(std::make_pair(17, "Seventeen"));
	my_map.insert(std::make_pair(18, "Eighteen"));
	my_map.insert(std::make_pair(19, "Nineteen"));
	my_map.insert(std::make_pair(20, "Twenty"));
	my_map.insert(std::make_pair(30, "Thirty"));
	my_map.insert(std::make_pair(40, "Forty"));
	my_map.insert(std::make_pair(50, "Fifty"));
	my_map.insert(std::make_pair(60, "Sixty"));
	my_map.insert(std::make_pair(70, "Seventy"));
	my_map.insert(std::make_pair(80, "Eighty"));
	my_map.insert(std::make_pair(90, "Ninety"));

	//divide into groups of three
	std::stack<string>  stck;
	int g = N % 1000;
	if(g != 0){
		stck.push( numberToString(g, my_map));
	}
	N = N / 1000;
	g = N % 1000;
	if(g != 0){
		stck.push("Thousand");
		stck.push( numberToString(g, my_map));
	}
	N = N / 1000;
	g = N % 1000;
	if(g != 0){
		stck.push("Million");
		stck.push( numberToString(g, my_map));
	}



	while(!stck.empty()){
		cout << stck.top();
		stck.pop();
	}
	cout << "Dollars" << endl;
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
					//int elem = atoi(tmp.c_str());
		       		//cout << "[" << elem << "]";
		       	   	values.push_back(atoi(tmp.c_str()));
		       	}

				if(values.size() == 1){
					textDollar(values[0]);
		       	}else{
		       		cout << "wrong entry in the input";
		       	}
		   }
		}
	}else{
		   cout << "Unable to open file";
	}

	//textDollar(101);
	return 0;
}
