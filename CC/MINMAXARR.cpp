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
	    int n; cin>>n;
        vi arr(n);
        loopi(i,0,n) cin>>arr[i];

        ll sum = 0, achievable, maxi = INT_MIN;     

        loopi(i,0,n){
            sum+= (ll)arr[i];
            achievable = (sum+i)/(i+1);   
            maxi = max(maxi, achievable);
        }
	    cout<<maxi<<endl;
	}
	return 0;
}
