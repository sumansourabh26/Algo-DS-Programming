#pragma once

//https://www.codechef.com/problems/HDELIVER
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

vi parent;

int findParent ( int x ) {
	if ( parent[x] == -1 ) {
		return x;
	}

	int p = findParent ( parent[x] );
	parent[x] = p;
	return p;
}


int mainFunction ( ) {
	run ( );
	ios_base::sync_with_stdio ( false ); cin.tie ( 0 );
	int q; cin >> q;
	while ( q-- ) {
		int n, m; cin >> n >> m;
		parent.assign ( n << 2, -1 );

		int counter = n;
		loopi ( i, 0, m ) {
			int v1, v2; cin >> v1 >> v2;
			int p1 = findParent ( v1 ), p2 = findParent ( v2 );
			if ( p1 != p2 ) {
				parent[p1] = p2;
			}
		}
		int qc; cin >> qc;
		while ( qc-- ) {
			int v1, v2; cin >> v1 >> v2;
			int p1 = findParent ( v1 ), p2 = findParent ( v2 );
			if ( p1 == p2 ) {
				cout << "YO\n";
			} else cout << "NO\n";
		}
	}

	return 0;
}