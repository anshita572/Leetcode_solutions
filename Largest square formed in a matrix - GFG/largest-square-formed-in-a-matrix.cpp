//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solveTab(vector<vector<int>>& mat,int& maxi)
{  int row=mat.size(); //total no of rows
    int col=mat[0].size(); //total no of columns
 vector<vector<int>>dp(row+1,vector<int>(col+1,0));
for(int i=row-1;i>=0;i--)
{for(int j=col-1;j>=0;j--)
{
    int bottom=dp[i+1][j];
        int diagnol=dp[i+1][j+1];
        int right=dp[i][j+1];
        if(mat[i][j]==1)
        {dp[i][j]=min(bottom,min(diagnol,right))+1;
        maxi=max(maxi,dp[i][j]);
        }
        else
        {dp[i][j]= 0;}
}
}
return dp[0][0];
}
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi=0;
        solveTab(mat,maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends