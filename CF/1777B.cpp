#include <bits/stdc++.h>
using namespace std;

#define MaxN 100002
#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define loopi(i,val,n) for(int i = val; i < n; i++)
#define loopd(i,val,n) for(int i = val; i >=n; i--)
template <typename A> ostream& operator<< ( ostream& cout, vector<A> const& v ) { cout << "["; for ( int i = 0; i < v.size ( ); i++ ) { if ( i ) cout << ", "; cout << v[i]; } return cout << "]"; }

ll fact[MaxN];

int main(){
    int q;
	cin >> q;

    memset(fact, 0, sizeof(fact));

    fact[1] = 1;
    loopi(i,2,MaxN) fact[i] = (i*fact[i-1])%MOD;

	while ( q-- ) {
        ll n; cin>>n;

        ll ans = (((n*(n-1))%MOD)*fact[n])%MOD;
        cout<<ans<<endl;

    }

}