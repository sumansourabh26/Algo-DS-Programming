#pragma once
#include <iostream>
#include <vector>
#include <fstream> 
#include <cmath>
#include <string>
#include <map>
#include <iterator>
#define MOD 1000000007

//https://www.hackerrank.com/challenges/maximum-palindromes/problem

using namespace std;
ifstream fin;
ofstream fout;

void setupIO ( ) {
	fin.open ( "myfile.txt", ios::in );    // open the streams
	fout.open ( "outfile.txt", ios::out );
}

int count_mat[100001][26];
int alpha_count[26];
int fact[100001], inv[100001];

int pow_mod ( int i, int pow ) {
	if ( pow == 1 ) return i;
	long long temp = pow_mod ( i, pow / 2 );
	temp = ( temp * temp ) % MOD;
	if ( pow % 2 ) temp = ( temp * i ) % MOD;
	return ( int ) ( temp );
}

int answerQuery ( int l, int r ) {

	for ( size_t i = 0; i < 26; i++ ) {
		alpha_count[i] = count_mat[r][i] - count_mat[l - 1][i];
	}

	int odd_count = 0;
	for ( size_t i = 0; i < 26; i++ ) {
		if ( alpha_count[i] % 2 ) odd_count++;
	}

	int half_sum = 0;
	for ( size_t i = 0; i < 26; i++ ) {
		half_sum += alpha_count[i] / 2;
	}
	long long answer = fact[half_sum];
	for ( size_t i = 0; i < 26; i++ ) {
		answer = ( answer * inv[alpha_count[i] / 2] ) % MOD;
	}
	if ( odd_count > 0 ) answer = ( answer * odd_count ) % MOD;
	return ( int ) ( answer );
}


void initialize ( string s ) {
	int length = s.length ( );
	memset ( count_mat, 0, sizeof ( count_mat ) );

	fact[0] = inv[0] = 1;
	for ( size_t i = 1; i < 100001; i++ ) {
		fact[i] = ( ( long long ) ( fact[i - 1] ) * ( long long ) i ) % MOD;
		inv[i] = pow_mod ( fact[i], MOD - 2 );
	}

	for ( size_t i = 1; i <= length; i++ ) {

		for ( size_t j = 0; j < 26; j++ ) {
			count_mat[i][j] = count_mat[i - 1][j];
		}
		count_mat[i][s[i - 1] - 'a']++;

	}
}

void run ( ) {
	string s;
	fin >> s;
	initialize ( s );
	int q, l, r;
	fin >> q;
	for ( size_t i = 0; i < q; i++ ) {
		fin >> l >> r;
		fout << answerQuery ( l, r ) << endl;
	}
}