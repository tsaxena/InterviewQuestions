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

vector<char> createCandidates(const string &ip, string &op){
	vector<char> candidates;
	for(size_t i = 0; i != ip.length(); i++){
		bool in_perm = false;
		for(size_t j = 0; j != op.length(); j++){
			if(ip[i] == op[j]){
				in_perm = true;
			}
		}
		if(!in_perm){
			candidates.push_back(ip[i]);
		}
	}
	return candidates;
}

void lexPermutations(const string &ip, string &op, int &count){
	if(ip.length() == op.length()){
		if(count != 0){
			cout << ",";
		}
		cout << op;
		count++;
		return;
	}
	vector<char> C = createCandidates(ip,op);
	for(vector<char>::iterator i = C.begin(); i != C.end();i++ ){
		//make move
		op.push_back(*i);
		//backtrack
		lexPermutations(ip, op, count);
		//unmake move
		op.erase(op.length() - 1);
	}
}

string countSort(string &s){
	vector<int> count(256, 0);

	//count frequency
	for(size_t i = 0; i < s.length(); i++ ){
		count[s[i] + 1]++;
	}

	//calculate index
	for(size_t r = 0; r < 129; r++){
		count[r + 1] = count[r + 1] + count[r];
	}

	//auxiliary string
	string aux(s); //important to allocate the same amount of space
	for(size_t i = 0; i < s.length(); i++ ){
		aux[count[s[i]]++] = s[i];
	}

	return aux;
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
				vector<string> values;
				stringstream line_stream(lineBuffer);
				string tmp;
				while(std::getline(line_stream, tmp, ' ')){
					//int elem = atoi(tmp.c_str());
		       		//cout << "[" << elem << "]";
		       	   	values.push_back(tmp);
		       	}

				if(values.size() == 1){
					string op;
					int count = 0;
					//cout << "UnSorted String [" << values[0] << "]" << endl;
					//cout << "Sorted String [" << countSort(values[0]) << "]" << endl;
					lexPermutations(countSort(values[0]), op, count);
					cout << endl;
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
