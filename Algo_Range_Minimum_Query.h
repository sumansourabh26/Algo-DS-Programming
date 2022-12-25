#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream> 
#include <iterator>
#include <algorithm>
#include <set> 
#include<queue>
using namespace std;

#define MOD (1e9+7)
#define ll long long int
#define vi vector<int>
#define loopi(i,data,n) for(int i = data; i < n; i++)
#define loopd(i,data,n) for(int i = data; i >=n; i--)e
template <typename A> ostream& operator<< ( ostream& cout, vector<A> const& v ) { cout << "["; for ( int i = 0; i < v.size ( ); i++ ) { if ( i ) cout << ", "; cout << v[i]; } return cout << "]"; }


/// <summary>
/// 1 based indexing used.
/// </summary>
int N;
vector<vector<int>> rmq;
void preprocess ( ) {
	for ( int i = 1, pow = 2; pow <= N; i++, pow = pow << 1 )
		for ( int j = 1; j <= ( N - pow + 1 ); j++ )
			rmq[i][j] = min ( rmq[i - 1][j], rmq[i - 1][j + ( pow / 2 )] );
}

int query ( int l, int r ) {
	int interval = r - l + 1;
	
	int p = ( int ) log2 ( interval );
	int pow_less_interval = 1 << p;
	return( min ( rmq[l][p], rmq[r - pow_less_interval + 1][p] ) );
}

int run ( ) {


	int q;
	cin >> N;
	cin >> q;

	rmq.assign ( 17, vector<int> ( N + 1 ) );
	for ( int i = 1; i <= N; i++ )	cin >> rmq[0][i];

	preprocess ( );

	while ( q-- ) {
		int l, r; cin >> l >> r;
		l++; r++;
		cout << query ( l, r );
	}


	return 0;
}