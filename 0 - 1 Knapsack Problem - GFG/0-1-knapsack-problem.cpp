//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int solve(int W, int wt[], int val[], int n,int i,vector<vector<int>>&dp)
    {
        if(i>=n || W==0)
        {return 0;}
        if(dp[i][W]!=-1)
        {return dp[i][W];}
        int include=0;
        if(W>=wt[i])
        {include=val[i]+solve(W-wt[i],wt,val,n,i+1,dp);}
        int exclude=solve(W,wt,val,n,i+1,dp);
        int ans=max(include,exclude);
        dp[i][W]=ans;
        return ans;
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { vector<vector<int>>dp(n+1,vector<int>(W+1,-1)); 
    //n+1=>row size,capacity+1=>column size 
       return solve(W,wt,val,n,0,dp);
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