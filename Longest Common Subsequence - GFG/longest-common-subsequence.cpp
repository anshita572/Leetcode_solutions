//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int solveSO(string &s1, string &s2)
    {
        int l1 = s1.length();
        int l2 = s2.length();
        vector<int> curr(l2 + 1, 0);
        vector<int> next(l2 + 1, 0);
        for (int i = l1 - 1; i >= 0; i--)
        {
            for (int j = l2 - 1; j >= 0; j--)
            {
                int ans = 0;
                if (s1[i] == s2[j])
                {
                    ans = 1 + next[j + 1];
                }
                else
                {
                    int op1 = next[j];
                    int op2 = curr[j + 1];
                    ans = max(op1, op2);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        return solveSO(s1, s2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends