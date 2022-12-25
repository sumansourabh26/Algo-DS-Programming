#pragma once

#include <iostream>
#include <vector>
#include <fstream> 
#include <iterator>


using namespace std;


void quicksort ( vector<int>& arr, int l, int r ) {
	if ( l >= r ) return;

	int pivot = l;
	for ( size_t i = l; i < r; i++ ) {
		if ( arr[i] <= arr[r] ) {
			int temp = arr[pivot]; arr[pivot] = arr[i]; arr[i] = temp;
			pivot++;
		}		
	}
	int temp = arr[pivot]; arr[pivot] = arr[r]; arr[r] = temp;
	quicksort ( arr, l, pivot - 1 );
	quicksort ( arr, pivot + 1, r );
}

void runH ( ) {
	vector<int> arr;
	int in_count;
	cin >> in_count;
	for ( size_t i = 0; i < in_count; i++ ) {
		int temp; cin >> temp;
		arr.push_back ( temp );	
	}
	quicksort ( arr, 0, arr.size()-1 );
	for ( size_t i = 0; i < in_count; i++ ) {
		cout << arr[i] << endl;
	}

}