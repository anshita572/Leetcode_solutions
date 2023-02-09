//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  
  long long solveSO(int N,int k,int T)
{
    vector<long long>prev(T+1,0);
    vector<long long>curr(T+1,0);
         prev[0]=1;
         for(int n=1;n<=N;n++)
         {
             for(int tar=1;tar<=T;tar++)
             {
               long long ans=0;
        for(int i=1;i<=k;i++)
        {if(tar-i>=0)
            {ans=ans+prev[tar-i];}
            }
       curr[tar]= ans;   
             }
             prev=curr;
         }
         return curr[T];
}
   long long solve(int k, int n, int tar)
    {
        if(n==0 && tar==0)
        {return 1;}
        if(n==0 && tar!=0)
        {return 0;}
        if(n!=0 && tar==0)
        {return 0;}
        if(tar<0)
        {return 0;}
        long long ans=0;
        for(int i=1;i<=k;i++)
        {ans=ans + solve(k,n-1,tar-i);}
        return ans ;
    }
    long long noOfWays(int M , int N , int X) {
        // return solve(M,N,X);
        return solveSO(N,M,X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends