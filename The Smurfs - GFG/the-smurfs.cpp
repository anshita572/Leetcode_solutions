//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        int redCount=0;
        int greenCount=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='R')
            {redCount++;}
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]=='G')
            {greenCount++;}
        }
        int blueCount=n-(redCount+greenCount);
        if((redCount==0 && greenCount==0) || (greenCount==0 && blueCount==0)
    || (redCount==0 && blueCount==0))
    {return n;}
        if((redCount % 2==0 && greenCount % 2==0 && blueCount % 2==0 )||
        (redCount&1 && greenCount&1 && blueCount&1 ))
        {return 2;}
        else
        {return 1;}
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends