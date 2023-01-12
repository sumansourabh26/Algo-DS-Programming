//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        
        int max_len = INT_MIN;
        int ansx, ansy;
        //odd length;
        for(int i = 0; i < s.length(); i++){
            int j = 0;
            while((((i-j)>=0)&&((i+j)<s.length())) &&(s[i+j] == s[i-j]) ){
                j++;
            }
            j--;
            if(max_len < (2*j+1)){
                ansx = i-j;
                ansy = i+j;
                max_len = 2*j+1;
            }
        }
        for(int i = 0; i < (s.length()-1); i++){
            if(s[i] != s[i+1]) continue;

            int j = 0;
            while((((i-j)>=0)&&((i+j+1)<s.length())) &&(s[i+1+j] == s[i-j]) ){
                j++;
            }
            j--;
            if(max_len < (2*j+2)){
                ansx = i-j;
                ansy = i+1+j;
                max_len = 2*j+2;
            }
        }
        return s.substr(ansx, ansy-ansx+1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends