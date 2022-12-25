#pragma once
#include <iostream>
#include <vector>
#include <fstream> 
#include <iterator>
#include <cmath>
#include <algorithm> 
#define MOD (1000000000+7)
#define ll long long
//https ://www.hackerrank.com/challenges/lego-blocks/problem

using namespace std;

ifstream fin;
ofstream fout;

void setupIO ( ) {
	fin.open ( "myfile.txt", ios::in );    // open the streams
	fout.open ( "outfile.txt", ios::out );
}

ll solid[1001], total[1001];
ll ways_row[1001];

ll pow_mod ( int i, int pow ) {
	if ( pow == 1 ) return i;
	long long temp = pow_mod ( i, pow / 2 );
	temp = ( temp * temp ) % MOD;
	if ( pow % 2 ) temp = ( temp * i ) % MOD;
	return ( temp );
}

int legoBlocks ( int n, int m ) {
	ways_row[0] = ways_row[1] = 1;
	ways_row[2] = 2; ways_row[3] = 4;
	for ( int i = 4; i <= m; i++ ) 
		ways_row[i] = ( ways_row[i - 1] + ways_row[i - 2] + ways_row[i - 3] + ways_row[i - 4] ) % MOD;
	
	total[0] = 1;
	solid[0] = 1;

	for ( int i = 1; i <= m; i++ ) total[i] = pow_mod ( ways_row[i], n );

	ll temp;

	for ( int i = 1; i <= m; i++ ) {
		temp = 0;
		for ( int j = 1; j < i; j++ ) temp = ( temp + ( solid[j] * total[i - j] ) % MOD ) % MOD;
		solid[i] = total[i] - temp;
	}
	int ans = ( int ) solid[m];
	if ( ans< 0 ) ans += MOD;
	return( ans%MOD );
}

void run ( ) {
	int n;
	fin >> n;
	while ( n-- ) {
		int n, m;
		fin >> n >> m;
		fout << legoBlocks ( n, m ) << endl;
	}
}