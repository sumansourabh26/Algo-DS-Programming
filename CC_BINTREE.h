#pragma once
//https://www.codechef.com/LP3TO403/problems/BINTREE
#include<iostream>
#include<cmath>
#include<vector>
#include<fstream> 
#include<cstring>
#include<climits>
#include<algorithm>
#include<stack>


using namespace std;

void  run ( ) {
	freopen ( "myfile.txt", "r", stdin );
	freopen ( "outfile.txt", "w", stdout );
}

#define MaxN 100001
#define debug 0
#define MOD (10 )
#define ll long long int
#define vi vector<int>
#define loopi(i,data,n) for(int i = data; i < n; i++)
#define loopie(i,data,n) for(int i = data; i <= n; i++)
#define loopd(i,data,n) for(int i = data; i >=n; i--)
template <typename A> ostream& operator<< ( ostream& cout, vector<A> const& v ) { cout << "["; for ( int i = 0; i < v.size ( ); i++ ) { if ( i ) cout << ", "; cout << v[i] << '\t'; } return cout << "]\n"; }

string DToB ( int num ) {
	string s;
	while ( num ) {
		if ( num & 1 ) s += '1';
		else s += '0';
		num >>= 1;
	}
	reverse ( s.begin ( ), s.end ( ) );
	return s;
}


int mainFunction ( ) {
	run ( );
	ios_base::sync_with_stdio ( false ); cin.tie ( 0 );
	int q; cin >> q;
	while ( q-- ) {
		int v1, v2; cin >> v1 >> v2;
		string s1 = DToB ( v1 ), s2 = DToB ( v2 );
		int i = 0;
		for ( ; ( i < s1.length ( ) ) && ( i < s2.length ( ) ); i++ ) {
			if ( s1[i] != s2[i] ) break;
		}
		cout << ( s1.length ( ) - i ) + ( s2.length ( ) - i ) << endl;
	}

	return 0;
}