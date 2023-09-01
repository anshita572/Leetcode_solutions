//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long solve(int i,int j,int nums[], vector<vector<int>>&dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        long long op1 = nums[i] + min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
        long long op2 = nums[j] + min(solve(i+1,j-1,nums,dp),solve(i,j-2,nums,dp));
        return dp[i][j] = max(op1,op2);
    }
    long long maximumAmount(int arr[], int n){
        vector<vector<int>>dp(n,vector<int>(n,-1));
        long long p1_score = solve(0,n-1,arr,dp);
        return p1_score;
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends