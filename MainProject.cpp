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


int main ( ) {
	run ( );
	int q;
	cin >> q;
	while ( q-- ) {
		cin >> n >> h;

		li.clear ( ); li.resize ( n );
		hi.clear ( ); hi.resize ( n );

		loopi ( i, 0, n ) {
			cin >> li[i] >> hi[i];
		}
		sort ( li.begin ( ), li.end ( ) );
		sort ( hi.begin ( ), hi.end ( ) );


	}
	return 0;
}