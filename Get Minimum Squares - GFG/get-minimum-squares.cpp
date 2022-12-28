//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solveTab(int n)
    {vector<int>dp(n+1,0);
      for(int j=1;j<=n;j++)
      { int ans=INT_MAX;
        for(int i=1;i*i<=j;i++)
        {ans=min(ans,1+dp[j-i*i]);}
        dp[j]=ans;
        }
        return dp[n];
    }
	int MinSquares(int n)
	{
	   return solveTab(n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends