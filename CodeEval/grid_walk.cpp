//============================================================================
// Name        : CodeEval.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <tr1/unordered_map>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

//====================================================================//
//grid path

typedef pair<int, int> Point;

bool isAccessable(int x, int y){
	int sum = 0;
	x = abs(x);
	y = abs(y);
	while(x != 0){
		sum = sum + x%10;
		x = x/10;
	}
	while(y != 0){
		sum = sum + y%10;
		y = y/10;
	}
	if(sum <= 19){
		return true;
	}
	return false;
}

bool isAlreadyVisited(int x, int y, map<Point, int> &grid_points){
	if( grid_points.find(make_pair(x,y)) != grid_points.end()){
		return true;
	}
	return false;
}


vector<Point> createCandidates(int x, int y){
	////if all the points around the point are inaccesable or visited then solution
	vector<Point> neighbors;
	neighbors.push_back(make_pair(x+1, y));
	neighbors.push_back(make_pair(x-1, y));
	neighbors.push_back(make_pair(x  , y+1));
	neighbors.push_back(make_pair(x  , y-1));

	return neighbors;
}
void gridWalk(int x, int y, map<Point, int> &grid_Points){
	if(!isAccessable(x, y) || isAlreadyVisited(x,y, grid_Points)){
			return;
	}

	grid_Points.insert(make_pair (make_pair(x,y),1));
	//create candidates
	vector<Point> C = createCandidates(x,y);
	for(vector<Point>::iterator i = C.begin(); i < C.end(); i++){
		gridWalk((*i).first, (*i).second, grid_Points);
	}
}



int main(int argc, char* argv[]) {
	map<Point, int> grid_points; //(X : Y)
	gridWalk(0,0, grid_points) ;
	cout << grid_points.size();
	return 0;
}
