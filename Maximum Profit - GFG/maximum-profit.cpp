//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int solveSO(int prices[] ,int k,int n)
    {  
       vector<vector<int>>curr(2,vector<int>(k+1,0));
       vector<vector<int>>next(2,vector<int>(k+1,0));
       for(int i=n-1;i>=0;i--)
       { for(int buy=0;buy<=1;buy++){
           for(int limit=1;limit<=k;limit++){
        int profit = 0;
        if(buy==1)
        {
            int canBuy = -prices[i] +next[0][limit];
            int skip = next[1][limit];
            profit = max(canBuy,skip);
        }
        else
        {
            int canSell = prices[i] + next[1][limit-1];
            int skip = next[0][limit];
            profit = max(canSell,skip); 
        }
    curr[buy][limit] = profit;   
       }
       }
       next=curr;
       }
        return curr[1][k];
    }
    int maxProfit(int K, int N, int A[]) {
        return solveSO(A,K,N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends