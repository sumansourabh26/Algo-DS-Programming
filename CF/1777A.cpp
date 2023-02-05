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

        int ans = 0;  
        int val; cin>>val;      
        int last_parity = val%2;

        loopi(i,1,n){
            cin>>val;
            if(last_parity != (val%2)){
                last_parity = (val%2);
            }
            else{
                ans++;
            }
        }
        cout<<ans<<endl;
        
        

    }
}