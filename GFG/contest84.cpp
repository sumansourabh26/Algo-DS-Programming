// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(string s, int K){
        vector<int> uninfacted(s.length());
        for(int i = 0;i < uninfacted.size(); i++){
            uninfacted[i] = i;
        }
        set<int> s_uninfected(uninfacted.begin(), uninfacted.end());
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                int range_l = max(0, i-K), range_r = min((int)s.length()-1, i+K);
                auto l = s_uninfected.lower_bound(range_l);
                auto r = s_uninfected.lower_bound(range_r);
                if(l==s_uninfected.end()) continue;
                if(r==s_uninfected.end()) (s_uninfected.erase(l,s_uninfected.end()));
                else s_uninfected.erase(l,++r);
            }
        }
        return(s.length() - s_uninfected.size());

    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.solve(s, K) << "\n";
    }
}  // } Driver Code Ends