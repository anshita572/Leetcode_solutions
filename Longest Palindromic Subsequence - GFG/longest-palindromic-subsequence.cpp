//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int solveTab(string &s1, string &s2)
    {
        int l1 = s1.length();
        int l2 = s2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = l1 - 1; i >= 0; i--)
        {
            for (int j = l2 - 1; j >= 0; j--)
            {
                if (s1[i] == s2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    int op1 = dp[i + 1][j];
                    int op2 = dp[i][j + 1];
                    dp[i][j] = max(op1, op2);
                }
            }
        }
        return dp[0][0];
    }
    int longestPalinSubseq(string A) {
      string s2= A;
       reverse(s2.begin(), s2.end());
        return solveTab(A,s2);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends