/*
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem :https://www.codechef.com/problems/CHCBOX
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


int main(){
    int q;
    cin>>q;
    while(q--){
        int n; cin>>n;
        vi arr(n);
        int maxv = 0, maxi = -1;
        loopi(i,0,n){
            cin>>arr[i];
            if(arr[i]>= maxv){
                maxv = max(maxv, arr[i]);
                maxi = i;
            }
        }
        //cout<<maxi<<maxv<<endl;
        int max_gap = 0;
        int gap_now = 1;
        for(int i = maxi+1;  ; i = (i+1)%n ){
            if(i == maxi ){
                max_gap = max( max_gap, gap_now);
                break;
            }
            if(arr[i] == maxv){
                max_gap = max( max_gap, gap_now);
                gap_now = 0;
            }
            else{
                gap_now++;
            }
        }
        //cout<<max_gap<<endl;
        cout<<max(0, max_gap - (n>>1))<<endl;
        
    }
}