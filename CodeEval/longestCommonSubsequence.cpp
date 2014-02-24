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
#include <set>
#include <algorithm>
#include <map>

using namespace std;

//====================================================================//
//longest common subsequence
int max(int a, int b){
	return (a > b)? a:b;
}

string longestCommonSubsequence(string &p, string &q){
	//base case
	int LCS[p.length()+1][q.length()+1] ; // store
	int Soln[p.length()+1][q.length()+1];

	for(size_t i = 0; i <= p.length(); i++){
		for(size_t j = 0; j <= q.length(); j++){
			if(i == 0 || j == 0){ //base case
				LCS[i][j] = 0;
				Soln[i][j] = -1;
			}else if(p[i-1] == q[j-1]){
				//cout << "match" << endl;
				LCS[i][j] = LCS[i-1][j-1] + 1;
				Soln[i][j] = 0;

			}else if(LCS[i-1][j] > LCS[i][j-1]){
				LCS[i][j] = LCS[i-1][j];
				Soln[i][j] = 1;
			}else{
				LCS[i][j] = LCS[i][j-1];
				Soln[i][j] = 2;
			}
		}
	}

	//print the subsequence
	// current method printing in the reverse direction
	int i = p.length();
	int j = q.length();
	string common_subsequence;
	while(i > 0 && j > 0){
		if(Soln[i][j] == 0){
			common_subsequence.insert(0,1, p[i-1]);
			i = i - 1;
			j = j - 1;
		}else if(Soln[i][j] == 1){
			i = i - 1;
		}else{
			j = j - 1;
		}
	}

	return common_subsequence;//LCS[n][m];
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
				while(std::getline(line_stream, tmp, ';')){
			       	values.push_back(tmp);
			    }
				//create map of indices and points
				values.push_back(tmp);
				//cout << "[" << values[0] << "]" << "    " << values[1];
				cout << longestCommonSubsequence(values[0], values[1]) << endl;
			}

		}

	}else{
		cout << "Unable to open file";
	}
	return 0;
}
