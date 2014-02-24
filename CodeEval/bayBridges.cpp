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

struct Point{
	double x;
	double y;
};


struct Bridge{
	int id;
	Point a;
	Point b;
};

struct less_second {
    typedef pair<int, vector<Bridge> > type;
    bool operator ()(type const& a, type const& b) const {
        return a.second.size() < b.second.size();
    }
};

/*--------------------------parse functions---------------------------*/
int parseID(string &id){
	stringstream line_stream(id);
	string tmp;
	std::getline(line_stream, tmp, ':');
	return atoi(tmp.c_str());
}

float parseX(string &x){
	stringstream line_stream(x);
	string tmp;
	std::getline(line_stream, tmp, '[');
	std::getline(line_stream, tmp, ',');
	return ::atof(tmp.c_str());
}

float parseY(string &y){
	stringstream line_stream(y);
	string tmp;
	std::getline(line_stream, tmp, ']');
	return ::atof(tmp.c_str());
}


Bridge parseBridgeRecord(vector<string> &record){

	for(vector<string>::iterator i = record.begin(); i != record.end(); i++){
		//cout << *i << endl;
	}

	Bridge bridge;
	bridge.id = parseID(record[0]);

	//parseX(record[1]);
	bridge.a.x = parseX(record[1]);
	bridge.a.y = parseY(record[2]);

	//cout << "[" << a.x << "]" << "[" << a.y << "]" << endl ;
	bridge.b.x = parseX(record[3]);
	bridge.b.y = parseY(record[4]);
	//cout << "[" << b.x << "]" << "[" << b.y << "]" << endl ;

	return bridge;
}


/*--------------------------bridge functions---------------------------*/
bool areIntersecting(Bridge bridge1, Bridge bridge2){

	//check if the lines are parallel to each other
	float slope1 = (bridge1.b.y - bridge1.a.y)/ (bridge1.b.x - bridge1.a.x);
	float slope2 = (bridge2.b.y - bridge2.a.y)/ (bridge2.b.x - bridge2.a.x);

	if(slope1 == slope2){
		return false;
	}

	//get intersection point of the bridges
	float b1 = bridge1.a.y - slope1 * bridge1.a.x;
	float b2 = bridge2.a.y - slope2 * bridge2.a.x;

	//find the intersection and check if it belongs to the segment
	float intersection_point_X = (b2-b1)/(slope1-slope2);

	float left_edge  = max(min(bridge1.a.x, bridge1.b.x), min(bridge2.a.x, bridge2.b.x));
	float right_edge = min(max(bridge1.a.x, bridge1.b.x), max(bridge2.a.x, bridge2.b.x));
	return left_edge < intersection_point_X && intersection_point_X < right_edge;

}




void bayBridges(vector<Bridge> bridges){
	tr1::unordered_map<int, vector<Bridge> > my_map;
	for(size_t i = 0; i < bridges.size() ; i++){
		for(size_t j = 0; j < bridges.size() ; j++){
			if(i != j && areIntersecting(bridges[i], bridges[j])){
				tr1::unordered_map<int, vector<Bridge> >::iterator index = my_map.find(bridges[i].id);
				if( index != my_map.end()){
					(*index).second.push_back(bridges[j]);
				}else{
					vector<Bridge> xbridges;
					xbridges.push_back(bridges[j]);
					my_map.insert(make_pair(bridges[i].id, xbridges));
				}
			}
		}
	}

	//create the build list
	vector<int> bridges_to_build ;
	for(vector<Bridge>::iterator i = bridges.begin(); i != bridges.end(); i++){
		if(my_map.find((*i).id) == my_map.end()){
			bridges_to_build.push_back((*i).id );
		}
	}

	//sort hashmap according the the number of bridges it intersects
	vector< pair< int, vector<Bridge> > > mapcopy;
	tr1::unordered_map<int, vector<Bridge> >::iterator  iterator = my_map.begin();
	for(; iterator != my_map.end(); iterator++){
		mapcopy.push_back( make_pair( (*iterator).first, (*iterator).second ));
	}
	sort(mapcopy.begin(), mapcopy.end(), less_second());

	// pick the bridge with least number bridges
	for(vector<pair<int, vector<Bridge> > >::iterator i = mapcopy.begin(); i != mapcopy.end(); i++){
		//cout << "Bridge" << (*i).first << "intersects with ";

		// if bridge does not intersect with to_be_built bridges
		// add to the build
		bool intersect_with_build = false;
		for(vector<Bridge>::iterator j = (*i).second.begin();
									 j != (*i).second.end() ;
									 j++){
			//cout << (*j).id ;
			if( find(bridges_to_build.begin(), bridges_to_build.end(), (*j).id ) != bridges_to_build.end()){
				intersect_with_build = true;
			}
		}
		if(!intersect_with_build){
			bridges_to_build.push_back((*i).first);
		}
	}

	sort(bridges_to_build.begin(), bridges_to_build.end());
	for(vector<int>::iterator i = bridges_to_build.begin(); i != bridges_to_build.end(); i++){
		cout << (*i) << endl;
	}
}


int main(int argc, char* argv[]) {
	ifstream file;
	string lineBuffer;
	file.open(argv[1]);

	if(file.is_open()){
		vector< Bridge > bridges;

		while (!file.eof()){
			getline(file, lineBuffer);
			if (lineBuffer.length() == 0){
				continue; //ignore all empty lines
			}else{
				vector<string> values;
				stringstream line_stream(lineBuffer);
				string tmp;
				while(std::getline(line_stream, tmp, ' ')){
			       	values.push_back(tmp);
			    }
				//create map of indices and points
				bridges.push_back(parseBridgeRecord(values));
			}
		}
		bayBridges(bridges);

	}else{
		cout << "Unable to open file";
	}
	return 0;
}
