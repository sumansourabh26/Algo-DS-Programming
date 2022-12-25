#pragma once

#include <iostream>
#include <vector>
#include <fstream> 
#include <iterator>


using namespace std;


void heapify ( vector<int>& arr, int index ) {
	if ( index > arr.size ( ) ) return;

	int max_index = index, l = ( index << 1 ) | 1, r = l + 1;
	if ( l < arr.size ( ) && arr[l] > arr[max_index] ) max_index = l;
	if ( r < arr.size ( ) && arr[r] > arr[max_index] ) max_index = r;

	if ( max_index == index ) return;

	int temp = arr[index];
	arr[index] = arr[max_index];
	arr[max_index] = temp;

	heapify ( arr, max_index );
}

void heapSort ( vector<int>& arr, vector<int>& result ) {

	if ( arr.empty ( ) ) return;

	result.push_back ( arr[0] );

	arr[0] = arr[arr.size ( ) - 1];
	arr.pop_back ( );

	heapify ( arr, 0 );
	heapSort ( arr, result );
}

void runH ( ) {
	int length, element;
	cin >> length;
	vector<int> arr;
	for ( size_t i = 0; i < length; i++ ) {
		cin >> element; arr.push_back ( element );
	}

	for ( int i = arr.size ( ) / 2; i >= 0; i-- ) {
		heapify ( arr, i );
	}
	vector<int> result;
	heapSort ( arr, result );

	for ( size_t i = 0; i < result.size ( ); i++ ) {
		cout << result[i] << endl;
	}
}