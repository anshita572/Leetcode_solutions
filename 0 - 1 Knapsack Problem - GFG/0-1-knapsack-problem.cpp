//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int solveSO(int cap, int wt[], int val[], int n)
    {vector<int>curr(cap+1,0);
     vector<int>prev(cap+1,0);
       for(int i=wt[0]; i<=cap; i++){
        prev[i] = val[0];
    }
     for(int W=0;W<=cap;W++)
        {
         for(int i=1;i<n;i++)
        {int inc=0;
        if(W>=wt[i])
       {  inc=val[i]+prev[W-wt[i]];}
        int exc=prev[W];
         curr[W]= max(inc,exc);
        }
        prev=curr;
        }
        return prev[cap];
    }
    int solveTab(int cap, int wt[], int val[], int n){
        vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
           for(int i=wt[0]; i<=cap; i++){
        dp[0][i] = val[0];
    }
      for(int i=1;i<n;i++)
        { for(int W=0;W<=cap;W++)
            {int inc=0;
        if(W>=wt[i])
       {  inc=val[i]+dp[i-1][W-wt[i]];}
        int exc=dp[i-1][W];
         dp[i][W]= max(inc,exc);}
        }
        return dp[n-1][cap];
    }
    int solve(int W, int wt[], int val[], int n,int i,vector<vector<int>>&dp)
    {
        if(i==0)
        {if(W>=wt[0]) //I am at last index and my knapsack still has capacity
        //to accomodate last item(wt[0]) then just take it
            {return val[0];}
        else
        {return 0;}
        }
        if(dp[i][W]!=-1)
        {return dp[i][W];}
        int inc=0;
        if(W>=wt[i])
       {  inc=val[i]+solve(W-wt[i],wt,val,n,i-1,dp);}
        int exc=solve(W,wt,val,n,i-1,dp);
        return dp[i][W]= max(inc,exc);
        
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //     vector<vector<int>>dp(n,vector<int>(W+1,-1));
    //   return solve(W,wt,val,n,n-1,dp);
    return solveTab(W,wt,val,n);
    // return solveSO(W,wt,val,n);
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