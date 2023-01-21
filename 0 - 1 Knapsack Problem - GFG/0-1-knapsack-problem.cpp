//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int solveTab(int cap, int wt[], int val[], int n)
    {vector<vector<int>>dp(cap+1,vector<int>(n+1,0));
        for(int W=0;W<=cap;W++)
        {
            for(int i=n-1;i>=0;i--)
            {int inc=0;
        if(W>=wt[i])
       {  inc=val[i]+dp[W-wt[i]][i+1];}
        int exc=dp[W][i+1];
         dp[W][i]= max(inc,exc);}
        }
        return dp[cap][0];
    }
    int solve(int W, int wt[], int val[], int n,int i,vector<vector<int>>&dp)
    {
        if(W<=0 || i>=n)
        {return 0;}
        if(dp[W][i]!=-1)
        {return dp[W][i];}
        int inc=0;
        if(W>=wt[i])
       {  inc=val[i]+solve(W-wt[i],wt,val,n,i+1,dp);}
        int exc=solve(W,wt,val,n,i+1,dp);
        return dp[W][i]= max(inc,exc);
        
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //     vector<vector<int>>dp(W+1,vector<int>(n,-1));
    //   return solve(W,wt,val,n,0,dp);
    return solveTab(W,wt,val,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends