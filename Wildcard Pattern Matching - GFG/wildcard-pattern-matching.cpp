//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    bool solve(int i, int j, string &s, string &p,
    vector<vector<int>>&dp){
       if(i == s.size() && j == p.size()){
            return true;
        }
        if(j == p.size() && i < s.size()){
            return false;
        }
        if(j < p.size() && i == s.size()){
            for(int k = j; k < p.size(); k++){
                if(p[k] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(i+1,j+1,s,p,dp);
        }
        if(p[j] == '*'){
            return dp[i][j] = solve(i+1,j,s,p,dp) || solve(i,j+1,s,p,dp);
        }
        return dp[i][j] = false;
    }
    int wildCard(string pattern,string str)
    {   vector<vector<int>>dp(str.size()+1,vector<int>(pattern.size()+1
    ,-1));
        return solve(0,0,str,pattern,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends