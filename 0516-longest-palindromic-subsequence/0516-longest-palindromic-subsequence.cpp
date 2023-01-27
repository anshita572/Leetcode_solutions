class Solution {
public:
    int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp)
    {if(i==s1.size()|| j==s2.size())
    {return 0;}
    if(dp[i][j]!=-1)
    {return dp[i][j];}
    if(s1[i]==s2[j])
    {return dp[i][j]= 1+solve(s1,s2,i+1,j+1,dp);}
    else
    {int op1=solve(s1,s2,i+1,j,dp);
    int op2=solve(s1,s2,i,j+1,dp);
    return dp[i][j]= max(op1,op2);}

    }
    int longestPalindromeSubseq(string s1) {
      string s2="";
      s2=s1;
      reverse(s2.begin(),s2.end());
      vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
       return solve(s1,s2,0,0,dp);
    }
};