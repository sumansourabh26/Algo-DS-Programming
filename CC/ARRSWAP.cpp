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
        int k; cin>>k;
        auto n = k<<1;
        int arr[n];
        loopi(i,0,n){
            cin>>arr[i];
        }
        sort(arr+0,arr+n);
        int mini = INT_MAX;
        for(int i = 0; i <= k; i++){
            mini = min(mini, arr[i+k-1]-arr[i]);
        }
        cout<<mini<<endl;
	}
	return 0;
}
