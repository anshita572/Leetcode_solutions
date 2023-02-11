//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
int solveSO(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    int profit = 0;
                    if (buy == 1)
                    {
                        int canBuy = -prices[i] + next[0][limit];
                        int skip = next[1][limit];
                        profit = max(canBuy, skip);
                    }
                    else
                    {
                        int canSell = prices[i] + next[1][limit - 1];
                        int skip = next[0][limit];
                        profit = max(canSell, skip);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return curr[1][2];
    }
int maxProfit(vector<int>&price){
   return solveSO(price);
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends