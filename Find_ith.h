#pragma once

#include <iostream>
#include <vector>
#include <fstream> 


/* find the ith element in the list of elements*/

using namespace std;
ifstream fin;
ofstream fout;

void setupIO ( ) {
	fin.open ( "myfile.txt", ios::in );    // open the streams
	fout.open ( "outfile.txt", ios::out );
}

int select_ith ( vector<int> &arr, int l, int r, int i ) {
	if ( r <= l ) return ( arr[l] );

	int curr_min = l;
	for ( int i = l; i < r; i++ ) {
		if ( arr[i] < arr[r] ) {
			int temp = arr[curr_min]; arr[curr_min] = arr[i]; arr[i] = temp;
			curr_min++;
		}
	}

	int temp = arr[curr_min]; arr[curr_min] = arr[r]; arr[r] = temp;
	temp = curr_min - l + 1;
	if (  temp == i ) return arr[curr_min];

	if ( temp < i ) return ( select_ith ( arr, curr_min + 1, r, i - temp ) );
	else return( select_ith ( arr, l, curr_min - 1, i ) );

}


void run ( ) {
	vector<int> arr;
	int in_count;
	fin >> in_count;
	for ( size_t i = 0; i < in_count; i++ ) {
		int temp; fin >> temp;
		arr.push_back ( temp );
	}

	fout << select_ith ( arr, 0, arr.size ( ) - 1, 3 );
}