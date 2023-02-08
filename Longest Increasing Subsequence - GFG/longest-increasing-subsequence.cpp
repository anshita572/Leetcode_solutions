//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int solveSO(int n, int nums[])
{
    vector<int>currRow(n+1,0);
    vector<int>nextRow(n+1,0);
for(int curr=n-1;curr>=0;curr--)
{for(int prev=curr-1;prev>=-1;prev--)
{ int inc=0;
    int exc=0;
    if(prev==-1 || nums[prev]<nums[curr])
    {inc=1+nextRow[curr+1];}
    exc=nextRow[prev+1];
    currRow[prev+1]= max(inc,exc);
}
nextRow=currRow;
}
   return nextRow[0]; 
}
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       return solveSO(n,a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends