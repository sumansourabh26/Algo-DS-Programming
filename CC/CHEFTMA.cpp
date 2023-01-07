/*
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem :https://www.codechef.com/problems/CHEFTMA
*/

#include <bits/stdc++.h>
using namespace std;

#define MaxN 100004
#define MOD (10 )
#define ll long long int
#define vi vector<int>
#define loopi(i,data,n) for(int i = data; i < n; i++)
#define loopie(i,data,n) for(int i = data; i <= n; i++)
#define loopd(i,data,n) for(int i = data; i >=n; i--)
template <typename A> ostream& operator<< (ostream& cout, vector<A> const& v) { cout << "["; for (int i = 0; i < v.size(); i++) { if (i) cout << ", "; cout << v[i] << '\t'; } return cout << "]\n"; }

vi diff, inc;

int main() {
	int q;
    cin>>q;
    while(q--){  
        int n,k,m;
        cin>>n>>k>>m;
        diff.resize(n);
        inc.resize(k+m);
        loopi(i,0,n){
            cin>>diff[i];
        }
        loopi(i,0,n){
            int t1;cin>>t1;
            diff[i] = diff[i]-t1;
        }
        sort(diff.begin(), diff.end(), greater<int>());

        loopi(i,0,k+m){
            cin>>inc[i];
        }
        sort(inc.begin(), inc.end(), greater<int>());
        int sum = 0;
        int i = 0,j = 0;
        while(i<n){
            if(j==(k+m)) {
                sum+=diff[i];
                i++;
                continue;
            }
            if(inc[j]>diff[i]) j++;
            else {
                diff[i] -= inc[j];
                sum += diff[i];
                i++, j++;
            }
        }
        cout<<sum<<endl;

    }
}