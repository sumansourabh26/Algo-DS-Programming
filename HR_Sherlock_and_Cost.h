#pragma once
#pragma once


#include <iostream>
#include <vector>
#include <fstream> 
#include <iterator>
#include <algorithm> 

//https://www.hackerrank.com/challenges/sherlock-and-cost/problem

using namespace std;

ifstream fin;
ofstream fout;

void setupIO ( ) {
	fin.open ( "myfile.txt", ios::in );    // open the streams
	fout.open ( "outfile.txt", ios::out );
}

int cost ( vector<int> b ) {

	vector<int> a ( b.size ( ) );


	int sumb = 0, sum1 = 0;
	int tb = 0, t1 = 0;
	for ( int i = 1; i < b.size ( ); i++ ) {
		sumb = max ( tb + abs ( b[i] - b[i - 1] ), t1 + abs ( b[i] - 1 ) );
		sum1 = tb + abs ( b[i - 1] - 1 );
		tb = sumb;
		t1 = sum1;
	}
	return max ( tb, t1 );
}

void run ( ) {
	int tc;
	fin >> tc;
	while ( tc-- ) {
		int length;
		fin >> length;
		vector<int> v ( length );
		for ( size_t i = 0; i < length; i++ ) {
			fin >> v[i];
		}
		fout << cost ( v ) << endl;
	}
}
