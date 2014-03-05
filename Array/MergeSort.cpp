/*
 * Sort.cpp
 *
 *  Created on: Feb 8, 2013
 *      Author: tripti
 */

#include <iostream>
#include <vector>
using namespace std;


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




void merge(std::vector<int>& A, int lo, int mid, int hi){

	std::vector<int> Aux(A);
	int i = lo;
	int j = mid + 1;
	for(int k = lo; k <= hi; k++){
		if(i > mid){ //left array exhausted
			A[k] = Aux[j++];
		}else if(j > hi){ //right array exhausted
			A[k] = Aux[i++];
		}else if( Aux[j] < Aux[i]){ //current key on right is less
			A[k] = Aux[j++];
		}else{
			A[k] = Aux[i++];
		}
	}
}

void mergeSort(std::vector<int>& A, int lo, int hi){
	if(hi <= lo){
		return;
	}

	int middle = lo + (hi - lo)/2;

	mergeSort( A, lo, middle);
	mergeSort( A, middle + 1, hi);
	merge(A, lo , middle, hi);

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


	mergeSort(arr, 0, 5);
	cout << "Sorted";
	printArray(arr);


	return 0;
}
