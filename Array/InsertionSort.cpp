/*
 * Sort.cpp
 *
 *  Created on: Feb 8, 2013
 *      Author: tripti
 */

#include <iostream>
#include <vector>
using namespace std;

// 1. INSERTION SORT
// 2. SELECTION SORT
// 3. BUBBLE SORT


#define QSIZE 10


void printArray(const std::vector<int> &arr){
	cout << "[";
	for(std::vector<int>::const_iterator i = arr.begin(); i != arr.end(); i++){
		cout << *i << ",";
	}
	cout << "]" << endl;
}

bool isSorted(const std::vector<int> &arr){
	for(size_t i = 1; i < arr.size(); i++){
		if( arr[i] < arr[i-1]){
			return false;
		}
	}
	return true;
}

void swap(std::vector<int> &arr,int i, int j ){
	int temp = 	arr[i];
	arr[i] 	= 	arr[j];
	arr[j]	=   temp;
}



void insertionSort(std::vector<int> &A){
	for(size_t i = 1; i < A.size(); i++){
		for(size_t j = i; j > 0 && A[j] < A[j-1]; j--){
				swap(A, j, j-1);
		}
	}
}



int main(){

	std::vector<int> arr;
	arr.push_back(5);
	arr.push_back(2);
	arr.push_back(4);
	arr.push_back(6);
	arr.push_back(1);
	arr.push_back(3);
	cout << "Unsorted ";
	printArray(arr);


	insertionSort(arr);
	cout << "Sorted: ";
	printArray(arr);

	return 0;
}
