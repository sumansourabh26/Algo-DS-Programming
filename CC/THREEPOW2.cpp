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
	    int l; cin>>l;
	    string s; cin>>s;
	    int c = 0;
	    loopi(i,0,l){
	        if(s[i]=='1') c++;
	    }
	    if(l==2 && c==2) {
	        cout<<"YES\n";
	        continue;
	    }
	    cout<<(((l>2) && (c<4))? "YES\n": "NO\n");
	}
	return 0;
}
