/*
* Author : SUMAN SOURABH
* EMAIL ID - sumansourabh26@gmail.com
* Problem :https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    
    bool ispar(string x)
    {
        int ans = true;
        stack<char> record;
        
        for(int i = 0; i < x.length(); i++){
            if(x[i]== '}'){
                if((!record.empty()) && record.top() == '{') record.pop();
                else return false;
            }
            else if((!record.empty()) && x[i]== ')'){
                if(record.top() == '(') record.pop();
                else return false;
            }
            else if((!record.empty()) && (x[i]== ']')){
                if(record.top() == '[') record.pop();
                else return false;
            }
            else{
                record.push(x[i]);
            }         
            
        }
        if(record.size()==0)return true;
        else return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends