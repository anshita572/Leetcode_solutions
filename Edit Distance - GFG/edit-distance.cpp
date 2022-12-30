//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   int solveTab(string s1, string s2)
    {
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));
        // converting base cases
        for (int j = 0; j < s2.length(); j++) // s1 has finished (s2>s1)
        {
            dp[s1.length()][j] = s2.length() - j;
        }
        for (int i = 0; i < s1.length(); i++)
        {
            dp[i][s2.length()] = s1.length() - i;
        }
        for (int i = s1.length() - 1; i >= 0; i--)
        {
            for (int j = s2.length() - 1; j >= 0; j--)
            {
                if (s1[i] == s2[j]) // match
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }    // no need of any operation ,check next char
                else // not match
                {
                    int insertAns = 1 + dp[i][j + 1]; // 1+ means we are counting that operation
                    int deleteAns = 1 + dp[i + 1][j];
                    int replaceAns = 1 + dp[i + 1][j + 1];
                    int ans = min(insertAns, min(deleteAns, replaceAns));
                    dp[i][j] = ans;
                }
            }
          
        }
          return dp[0][0];
    }
    int editDistance(string s, string t) {
       return solveTab(s,t);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends