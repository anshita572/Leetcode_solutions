//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define mod 1000000007
class Solution{
public:
    long int solve(int N, vector<long int>&dp)
    {
        if(N==1)
        {return 0;}
        if(N==2)
        {return 1;}
        if(dp[N]!=-1)
        {return dp[N];}
        long int ans=(N-1)*(solve(N-1,dp)%mod +solve(N-2,dp)%mod)%mod;
        return dp[N]= ans;
    }
    long int disarrange(int N){
        vector<long int>dp(N+1,-1);
        return solve(N,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends