#pragma once

#include <iostream>
#include <vector>
#include <fstream> 
#include <cmath>
#include <string>
#include <map>
#include <iterator>


//https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem?isFullScreen=true

using namespace std;
ifstream fin;
ofstream fout;

void setupIO ( ) {
	fin.open ( "myfile.txt", ios::in );    // open the streams
	fout.open ( "outfile.txt", ios::out );
}



string isValid ( string s ) {

	map<int, int> count1;
	map<int, int>::iterator itr;
	bool success = true;

	for ( size_t i = 0; i < s.length ( ); i++ ) {
		count1[s[i]]++;
	}

	itr = count1.begin ( );
	int c1 = 0;
	for ( ; itr != count1.end ( ); itr++ ) {
		if ( itr->second == 1 ) {
			count1.erase ( itr );
			if ( count1.size() == 0 ) {
				success = true;
			}
			else {
				itr = count1.begin ( );
				int val1 = itr->second;
				itr++;
				for ( ; itr != count1.end ( ); itr++ ) {
					if ( itr->second != val1 ) {
						success = false;
						break;
					}
				}
			}
			if ( success ) return "YES";
			else return "NO";

		}
	}

	itr = count1.begin ( );
	int val0 = itr->second;

	for ( ; itr != count1.end ( ); itr++ ) {
		itr->second -= val0;
	}

	int temp = 0;

	success = true;
	itr = count1.begin ( ); itr++;
	for ( ; itr != count1.end ( ); itr++ ) { // 0001000 OR 0000000

		if ( itr->second == 1 ) temp++;
		if ( itr->second > 1 || itr->second < 0 ) {
			success = false;
			break;
		}
	}
	if ( success && temp <= 1 ) return "YES";

	success = true;
	itr = count1.begin ( ); itr++;
	for ( ; itr != count1.end ( ); itr++ ) { //-1 -1 -1 -1 -1
		if ( itr->second != -1 ) {
			success = false;
			break;
		}

	}
	if ( success ) return "YES";
	else return "NO";

}

void run ( ) {
	string s;
	fin >> s;
	fout << isValid ( s );
}