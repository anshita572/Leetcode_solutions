//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{//Maximise the cut segments (GFG practice)
    public:
    int solveTab(int n, int x, int y, int z)
    {vector<int>dp(n+1,INT_MIN);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {  if(i>=x)
       {dp[i]=max(dp[i],dp[i-x]+1);}
       if(i>=y)
       {dp[i]=max(dp[i],dp[i-y]+1);}
       if(i>=z)
       {dp[i]=max(dp[i],dp[i-z]+1);}
        
    }
        return dp[n];
    }
    int solve(int n, int x, int y, int z,vector<int>&dp)
    {
        if(n==0)
        {return 0;}
        if(n<0)
        {return INT_MIN;}
        if(dp[n]!=-1)
        {return dp[n];}
        int op1;
        int op2;
        int op3;
       op1=solve(n-x,x,y,z,dp);
        op2=solve(n-y,x,y,z,dp);
        op3=solve(n-z,x,y,z,dp);
        int ans= 1+max(op1,max(op2,op3));
        dp[n]=ans;
        return ans;
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
    //  vector<int>dp(n+1,-1);
    //   int ans= solve(n,x,y,z,dp);
    int ans=solveTab(n,x,y,z);
       if(ans<0)
       {ans=0;}
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends