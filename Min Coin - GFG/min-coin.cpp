//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solveMemo(vector<int>& coins, int amount,vector<int>&dp)
{if(amount==0)
{return 0;}
if(amount < 0)
{return INT_MAX;}
if(dp[amount]!=-1)
{return dp[amount];}
int mini=INT_MAX;
for(int i=0;i<coins.size();i++)
{int ans=solveMemo(coins,amount-coins[i],dp);
if(ans!=INT_MAX)
{mini=min(mini,ans+1);}
}
dp[amount]=mini;
 return mini;
}
	int MinCoin(vector<int>nums, int amount)
	{
	      vector<int>dp(amount+1,-1);
        int ans= solveMemo(nums,amount,dp);
        
        if(ans==INT_MAX)
        {ans=-1;}
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends