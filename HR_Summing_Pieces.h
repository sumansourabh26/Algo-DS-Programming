#pragma once
#include <iostream>
#include <vector>
#include <fstream> 
#include <iterator>
#include <algorithm> 
#define MOD 1000000007
#define ll long long
//https://www.hackerrank.com/challenges/summing-pieces/

using namespace std;

ifstream fin;
ofstream fout;

void setupIO ( ) {
	fin.open ( "myfile.txt", ios::in );    // open the streams
	fout.open ( "outfile.txt", ios::out );
}


int pow_mod ( int pow ) {
    if ( pow == 0 ) return( 1 );
    if ( pow == 1 ) return 2;
    long long temp = pow_mod ( pow / 2 );
    temp = ( temp * temp ) % MOD;
    if ( pow % 2 ) temp = ( temp * 2 ) % MOD;
    return ( int ) ( temp % MOD );
}

int summingPieces ( vector<int> arr ) {

    int t1 = ( 3 * pow_mod ( arr.size ( ) - 1 ) ) % MOD;
    int sum = 0;
    for ( int i = 1; i <= arr.size ( ); i++ ) {
        sum = ( sum + ( ( ll ) ( t1 - pow_mod ( arr.size ( ) - i ) - pow_mod ( i - 1 ) ) * ( ll ) arr[i - 1] ) % MOD ) % MOD;
    }
    sum = sum % MOD;
    if ( sum < 0 ) sum = ( sum + MOD ) % MOD;
    return sum;
}

void run ( ) {
	
	int length;
	fin >> length;
	vector<int> v ( length );
	for ( size_t i = 0; i < length; i++ ) {
		fin >> v[i];
	}
	fout << summingPieces ( v ) << endl;
	
}
