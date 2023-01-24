class Solution {
public: 
int solveSO(string& s1, string& s2)
{vector<int>curr(s2.length()+1,0);
vector<int>next(s2.length()+1,0);
for(int i=s1.length()-1;i>=0;i--)
{for(int j=s2.length()-1;j>=0;j--)
{if(s1[i]==s2[j])
{curr[j]= 1+next[j+1];}
else
{int op1=next[j];
int op2=curr[j+1];
curr[j]=max(op1,op2);}

}
next=curr;
}
return next[0];
}
int solveTab(string& s1, string& s2)
{ vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
for(int i=s1.length()-1;i>=0;i--)
{for(int j=s2.length()-1;j>=0;j--)
{if(s1[i]==s2[j])
{dp[i][j]= 1+dp[i+1][j+1];}
else
{int op1=dp[i+1][j];
int op2=dp[i][j+1];
dp[i][j]=max(op1,op2);}

}
}
return dp[0][0];
}
int solve(string& s1, string& s2,int i,int j,  vector<vector<int>>&dp)
{if(i>=s1.length() || j>=s2.length())
{return 0;}
if(dp[i][j]!=-1)
{return dp[i][j];}
if(s1[i]==s2[j])
{return dp[i][j]= 1+solve(s1,s2,i+1,j+1,dp);}
else
{int op1=solve(s1,s2,i+1,j,dp);
int op2=solve(s1,s2,i,j+1,dp);
return dp[i][j]=max(op1,op2);
}

}
 int longestCommonSubsequence(string s1, string s2) {
    //  vector<vector<int>>dp(s1.length(),vector<int>(s2.length(),-1));
    //   return solve(s1,s2,0,0,dp);
    // return solveTab(s1,s2);
     return solveSO(s1,s2);
        
    }
};