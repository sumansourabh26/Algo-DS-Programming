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
        string s;
        cin>>s;
        int l = s.length();
        bool found = false;
        for(int i = 1; i < l-1;i++){
            if(found) break;
            for(int j = 1; i+j < l; j++){       
                if(found) break;
                if(((s.substr(0,i) <= s.substr(i,j))&& (s.substr(i,j) >=s.substr(i+j,(l-i-j)) ))||
                ((s.substr(0,i) >= s.substr(i,j))&& (s.substr(i,j) <=s.substr(i+j,(l-i-j)) ))){
                    cout<<s.substr(0,i) <<' ' <<s.substr(i,j) <<' '<< s.substr(i+j,(l-i-j))<<endl;
                    found = true;
                }
                
                
            }
        }
        

    }
}