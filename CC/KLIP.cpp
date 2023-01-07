/*
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem :https://www.codechef.com/problems/KLIP
*/

#include <bits/stdc++.h>
using namespace std;

#define MaxN 100004
#define MOD (10 )
#define ll long long int
#define vi vector<int>
#define pi pair<int,int>
#define loopi(i,data,n) for(int i = data; i < n; i++)
#define loopie(i,data,n) for(int i = data; i <= n; i++)
#define loopd(i,data,n) for(int i = data; i >=n; i--)
template <typename A> ostream& operator<< (ostream& cout, vector<A> const& v) { cout << "["; for (int i = 0; i < v.size(); i++) { if (i) cout << ", "; cout << v[i] << '\t'; } return cout << "]\n"; }


int main() {
	int q;
    cin>>q;
    while(q--){  
        int n, k;
        cin>>n>>k;
        string s; cin>>s;

        int count1 = 0;
        for(int i = 0; i <= n-k; i++){
            if(s[i] == '1') count1++;
            cout<<0;
        }
        for(int i = n-k+1; i< n; i++){
            if(count1%2){
                cout<< (s[i]=='0')? 1:0;
            }
            else {
                cout<<s[i];
            }
        }
        cout<<endl;


    }
}