#include <iostream>
#include <vector>
using namespace std;

#define QSIZE 10


void printArray(const std::vector<int> &arr){
	cout << "[";
	for(std::vector<int>::const_iterator i = arr.begin(); i != arr.end(); i++){
		cout << *i;
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



int choosePivot(std::vector<int> &arr){
	return 0;
}

int partition(std::vector<int> &A, int lo, int hi){

	//choosePivot(arr);
	int pivotPoint = lo;
	int pivot = A[pivotPoint];

	//move to the front of the array
	swap(A, lo, pivotPoint);
	int i = lo;
	int j = hi + 1;
	while(true){
		//scan from left
		while(A[++i]< pivot){
			if(i == hi){
				break;
			}
		}
		//scan from right
		while(A[--j] > pivot){
			if(j == lo){
				break;
			}
		}

		if(i >= j){
			break;
		}
		swap(A, i, j);
	}
	swap(A, lo, j);
	return j;
}


void quickSort(std::vector<int> & A, int lo, int hi){
	if(hi <= lo){
		return;
	}
	int indx = partition(A, lo, hi);
	quickSort(A, lo, indx - 1);
	quickSort(A, indx + 1	, hi );
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

	cout << "Sorted";
	quickSort(arr, 0, arr.size() - 1);
	printArray(arr);


	return 0;
}
