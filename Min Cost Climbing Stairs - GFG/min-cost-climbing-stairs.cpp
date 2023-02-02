//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int solveSO(vector<int>& cost,int n)
{int prev1=cost[1];
int prev2=cost[0];
for(int i=2;i<n;i++)
{ int ans=cost[i]+min(prev1,prev2);
        prev2=prev1;
        prev1=ans;
}
return min(prev1,prev2);
}
    int minCostClimbingStairs(vector<int>&cost ,int N) {
           return solveSO(cost,N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends