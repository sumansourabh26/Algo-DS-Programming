/*
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem :https://www.codechef.com/problems/NCOPIES
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
        int n, rep;
        cin>>n>>rep;
        string s; cin>>s;
        int sum = 0;
        loopi(i,0,n) sum+= (s[i]-'0');
        //cout<<"s:"<<sum<<endl;
        if(sum == 0){
            cout<<(ll)n*(ll)rep<<endl;
            continue;
        }
        if(rep%2){ //odd
            if(sum%2){
                cout<<0<<endl;
                continue;
            }
            else{
                int as = 0;
                int counter = 0;
                for(int i = 0; i < n; i++){
                    as+=(s[i]-'0');
                    if(as == (sum/2)) counter++;
                }
                cout<<counter<<endl;
            }
        }
        else{
            string s2 = s.append(s);
            int as = 0;
            int counter = 0;
            for(int i = 0; i < (n<<1); i++){
                as+=(s2[i]-'0');
                if(as == (sum)) counter++;
            }
            cout<<counter<<endl;
            
        }

    }
}