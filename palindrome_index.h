#pragma once
#pragma once
#pragma once
//https://www.hackerrank.com/challenges/palindrome-index/problem
#include <iostream>
#include <vector>
#include <fstream> 
#include <cmath>
#include <string>

using namespace std;
ifstream fin;
ofstream fout;
string s;

void setupIO ( ) {
	fin.open ( "myfile.txt", ios::in );    // open the streams
	fout.open ( "outfile.txt", ios::out );
}

/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
bool isPalindrome ( string s, int l, int r );
int palindromeIndex ( string s ) {
	int ans = 0, mid = s.length ( ) / 2, l = 0, r = s.length ( ) - 1;
	for ( ; l < mid; l++, r-- ) {
		if ( s[l] != s[r] ) {
			if ( isPalindrome ( s, l + 1, r ) ) return ( l );
			else if ( isPalindrome ( s, l, r - 1 ) )return( r );
			else return( -2 );
		}
	}
	return -1;
}

bool isPalindrome ( string s, int l, int r ) {

	for ( ; l < r; l++, r-- ) {
		if ( s[l] != s[r] ) {
			return false;
		}
	}
	return true;

}

int run ( ) {
	int length;

	fin >> length;

	for ( int i = 0; i < length; i++ ) {

		fin >> s;
		fout << palindromeIndex ( s ) << endl;
	}
	return 0;
}

