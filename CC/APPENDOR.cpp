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
        int n, target; 
        cin>>n>>target;

        int or_val = 0;
        loopi(i,0,n){
            int t ; cin>>t;
            or_val = or_val|t;
        }
        int ans = 0;
        int i = 0;
        for(; i < 31; i++){
            if((or_val%2 == 1) && (target%2 == 0)){
                cout<<-1<<endl;
                break;
            }
            if((or_val%2 == 0) && (target%2 == 1)){
                ans += (1<<i);
            }
            target = target >>1;
            or_val = or_val>>1;
        }
        if( i ==31){
            cout<<ans<<endl;
        }

	}
	return 0;
}
