/*
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem :https://www.codechef.com/problems/DEVPERF
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

vector<string> table;

int main() {
	int q;
    cin>>q;
    while(q--){        
        int row,col; cin>>row>>col;
        pair<int,int> pmaxX, pminX, pmaxY, pminY;
        int maxX = INT_MIN, minX = INT_MAX, maxY = INT_MIN, minY = INT_MAX;

        loopi(i,0,row){
            string str; cin>>str;
            loopi(j,0,col){
                if(str[j] == '*'){
                    if(i<minX){
                        minX = i;
                        pminX = {i,j};
                    }
                    if(i>maxX){
                        maxX = i;
                        pmaxX = {i,j};
                    }
                    if(j<minY){
                        minY = j;
                        pminY = {i,j};
                    }
                    if(j>maxY){
                        maxY = j;
                        pmaxY = {i,j};
                    }
                }    
            }
        }
        if(maxY == INT_MIN){
            cout<<0<<endl;
            continue;
        }
        int ans = INT_MAX;
        loopi(i,0,row){
            loopi(j,0,col){
                int t1 = max(abs(pmaxX.first - i), abs(pmaxX.second - j));
                int t2 = max(abs(pminX.first - i), abs(pminX.second - j));
                int t3 = max(abs(pmaxY.first - i), abs(pmaxY.second  - j));
                int t4 = max(abs(pminY.first - i), abs(pminY.second - j));
                int t5 = max(max(t1,t2), max(t3,t4));
                ans = min(ans,t5);
            }
        }
        cout<<ans+1<<endl;

    }
	return 0;
}

