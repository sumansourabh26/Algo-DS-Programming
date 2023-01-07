/*
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem :https://www.codechef.com/problems/SUBMEDIA
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

vi diff, inc;
bool func(pi a, pi b){
    return (a.second < b.second);
}
int main() {
	int q;
    cin>>q;
    while(q--){  
        int n, len;
        cin>>n>>len;
        vector<pair<int,int>> arr(n);
        loopi(i,0,n) {
            cin>>arr[i].first;
            arr[i].second = i;
        }
        sort(arr.begin(), arr.end());
        //cout<< n-len+((len-1)/2)<<endl;
        cout<<arr[n-len+((len-1)/2)].first<<endl;
        
        sort(arr.end()-len, arr.end(), func);

        for(auto itr = arr.end()-len; itr!=arr.end(); itr++){
            cout<<(*itr).first<<' ';
        }
        cout<<endl;

    }
}