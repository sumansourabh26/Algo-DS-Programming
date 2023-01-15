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
        int n2 = n<<1;

        vi arr(n2);
        loopi(i,0,n2) cin>>arr[i];
        vi copy(arr);
        sort(arr.begin(), arr.end());
        
        int mid = arr[n-1];
        int destination = n;
        ll ans = 0;
        loopi(i,0,destination){            
            if(copy[i] > mid ){
                ans += (ll)(destination-i);
                destination++;
            }
        }
        cout<<ans<<endl;
    }
}