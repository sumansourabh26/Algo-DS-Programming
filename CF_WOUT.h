#pragma once
//https://www.codechef.com/problems/WOUT

#include<iostream>
#include<cmath>
#include<vector>
#include<fstream> 
#include<cstring>
#include<climits>
#include<algorithm>
#include<queue>



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



int n, h;
vi li, hi;
vi opening;


int mainFunc ( ) {
	//	run ( );
	int q;
	cin >> q;
	while ( q-- ) {

		cin >> n >> h;

		li.clear ( ); li.resize ( n );
		hi.clear ( ); hi.resize ( n );
		opening.clear ( ); opening.resize ( n );

		loopi ( i, 0, n ) {
			cin >> li[i] >> hi[i];
		}
		sort ( li.begin ( ), li.end ( ) );
		sort ( hi.begin ( ), hi.end ( ) );

		int left = 0, right = 0;
		ll boxSum = 0;
		loopi ( i, 0, h ) {

			while ( left < n && hi[left] < i ) left++;
			while ( right < n && li[right] <= i ) right++;
			opening[i] = n - ( right - left );
			boxSum += ( ll ) opening[i];
		}
		ll minSum = boxSum;
		loopi ( i, h, n ) {
			while ( left < n && hi[left] < i ) left++;
			while ( right < n && li[right] <= i ) right++;
			opening[i] = n - ( right - left );
			boxSum += ( ll ) ( opening[i] - opening[i - h] );
			minSum = min ( minSum, boxSum );
		}
		cout << minSum << endl;


	}
	return 0;
}