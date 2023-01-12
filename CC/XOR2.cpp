#include <bits/stdc++.h>
using namespace std;
#define MOD (1e9+7)
#define ll long long
#define vi vector<int>
#define loopi(i,val,n) for(int i = val; i < n; i++)
#define loopd(i,val,n) for(int i = val; i >=n; i--)
template <typename A> ostream& operator<< ( ostream& cout, vector<A> const& v ) { cout << "["; for ( int i = 0; i < v.size ( ); i++ ) { if ( i ) cout << ", "; cout << v[i]; } return cout << "]"; }



int main ( ) {
	int q;
	cin >> q;
	while ( q-- ) {
        ll x, y;
        cin>>x>>y;
        ll ans =  3*x*y - x - y;
        if(ans > 1e18){
            ans =  x*y - x - y;
        }
        cout<<ans<<endl;
    }
}

