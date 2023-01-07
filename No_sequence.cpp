/**
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem : https://codeforces.com/contest/1779
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

void  run() {
    freopen("myfile.txt", "r", stdin);
    freopen("outfile.txt", "w", stdout);
}

ll powarr[101];
vi ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    run();
    int q;
    cin >> q;
    while (q--) {
        int n, k, s;
        cin >> n >> k >> s;
        
        ans.clear();
        memset(powarr, 0, sizeof(powarr));

        int i = 1; powarr[0] = 1;
        for (; i < n; i++) {
            powarr[i] = powarr[i - 1] * k;
        }
        int sum = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (s > 0) {
                if (((powarr[j] - 1) / (k - 1)) < s) {
                    ans.push_back(1);
                    s -= powarr[j];
                }
                else  ans.push_back(0); // (powarr[j] > s)
            }
            else if (s < 0) {
                if (((powarr[j] - 1) / (k - 1)) < (-s)) {
                    ans.push_back(-1);
                    s += powarr[j];
                }
                else ans.push_back(0);

            }
            else ans.push_back(0);

        }
        if (s == 0) {
            for (int i = n - 1; i >= 0; i--) {
                cout << ans[i] << ' ';
            } 
        }
        else {
            cout << -2 ;
        }
        cout << endl;






    }
}