#pragma once


#include <iostream>
#include <vector>
#include <fstream> 
#include <iterator>
#include <algorithm> 

//https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

using namespace std;

ifstream fin;
ofstream fout;

void setupIO ( ) {
	fin.open ( "myfile.txt", ios::in );    // open the streams
	fout.open ( "outfile.txt", ios::out );
}

int lcs[101][101];
int choice[101][101];


vector<int> longestCommonSubsequence ( vector<int> a, vector<int> b ) {
	for ( int i = 0; i < 101; i++ ) {
		lcs[0][i] = lcs[i][0] = 0;
		choice[0][i] = choice[i][0] = 0;
	}
	int l1 = a.size ( ), l2 = b.size ( );

	for ( int i = 1; i <= l1; i++ ) {
		for ( int j = 1; j <= l2; j++ ) {

			if ( a[i-1] == b[j-1] ) {
				choice[i][j] = a[i-1];
				lcs[i][j] = 1 + lcs[i - 1][j - 1];
			} else {
				if ( lcs[i][j - 1] > lcs[i - 1][j] ) {
					lcs[i][j] = lcs[i][j - 1];
					choice[i][j] = -1; //left 
				} else {
					lcs[i][j] = lcs[i - 1][j];
					choice[i][j] = -2; //up l1/row not matched
				}
			}
		}
	}
	vector<int> ans;
	int i = l1, j = l2;
	while ( lcs[i][j] != 0 ) {
		if ( choice[i][j] == -1 ) j--;
		else if ( choice[i][j] == -2 ) i--;
		else {
			ans.push_back ( choice[i][j] );
			i--; j--;
		}
	}
	//fout << endl;
	//for ( int i = 0; i <= l1; i++ ) {
	//	for ( int j = 0; j <= l2; j++ ) {
	//		fout << lcs[i][j] << choice[i][j] << "\t";
	//	}
	//	fout << endl;
	//}
	reverse ( ans.begin ( ), ans.end ( ) );
	return ans;
}

void run ( ) {
	int l1, l2, l3;
	fin >> l1 >> l2;
	

	vector<int> v1 ( l1 ), v2 ( l2 ), v3;

	for ( size_t i = 0; i < l1; i++ ) {
		fin >> v1[i];
	}
	for ( size_t i = 0; i < l2; i++ ) {
		fin >> v2[i];
	}
	v3 = longestCommonSubsequence ( v1, v2 );
	//fout << lcs[l1][l2] << endl;
	for ( size_t i = 0; i < v3.size ( ); i++ ) {
		fout << v3[i] << ' ';
	}
}