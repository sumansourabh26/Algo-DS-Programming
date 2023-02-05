#include <bits/stdc++.h>
using namespace std;

#define MaxN 100002
#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define loopi(i,val,n) for(int i = val; i < n; i++)
#define loopd(i,val,n) for(int i = val; i >=n; i--)
template <typename A> ostream& operator<< ( ostream& cout, vector<A> const& v ) { cout << "["; for ( int i = 0; i < v.size ( ); i++ ) { if ( i ) cout << ", "; cout << v[i]; } return cout << "]"; }

int main(){
    int q;
	cin >> q;
    while(q--){
        int x[4];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        
        ll a = 0, b = 0;
        ll ans = 0;
        //step 1
        a = x[0]; b = x[0];
        ans = x[0];
        

        ans += 2*(min(x[1], x[2]));
        
        ll remaining = x[3] + max(x[1],x[2])-min(x[1],x[2]);

        if(x[0]>=remaining) {
            ans+=(remaining);
        }else{
            ans += (x[0]+1);
        }
        cout<<ans<<endl;


    }
}