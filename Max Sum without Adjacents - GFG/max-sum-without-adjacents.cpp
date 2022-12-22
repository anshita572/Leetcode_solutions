//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
int solveSO(int *arr, int n)
{int next1=0;
int next2=0;
int curr;
         for(int i=n-1;i>=0;i--)
         {int include=arr[i]+next2;
         int exclude=next1;
         curr=max(include,exclude);
             next2=next1;
             next1=curr;
         }
         return curr;}
         
         
     int solveTab(int *arr, int n)
     {   vector<int>dp1(n+2,0);
         for(int i=n-1;i>=0;i--)
         {int include=arr[i]+dp1[i+2];
         int exclude=dp1[i+1];
         dp1[i]=max(include,exclude);}
         return dp1[0];
     }
     int solve(int *arr, int n,int i, vector<int>&dp)
     {
         if(i>=n)
         {return 0;}
         if(dp[i]!=-1)
         {return dp[i];}
         int include=arr[i]+solve(arr,n,i+2,dp);
         int exclude=solve(arr,n,i+1,dp);
         int ans=max(include,exclude);
         dp[i]=ans;
         return ans;
     }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	   // vector<int>dp(n,-1);
	   //return solve(arr,n,0,dp);
	   //return solveTab(arr,n);
	   return solveSO(arr,n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends