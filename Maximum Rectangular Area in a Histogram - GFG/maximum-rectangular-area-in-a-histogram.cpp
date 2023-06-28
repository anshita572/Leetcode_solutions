//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector< long long> nextSmallerElement(long long arr[],int n)
    {
        vector<long long>ans(n);
	    stack<long long>s;
    	s.push(-1);
    for(int i=n-1;i>=0;i--)
    {
	    while(s.top()!=-1 && arr[s.top()] >= arr[i]) //we don't have
	                     //arr[-1] , that's why writing s.top()!=-1
	     {
		     s.pop();
	     }
	    ans[i]=s.top();
	     s.push(i);
 
     }
    return ans;
        
    }
    vector< long long> prevSmallerElement(long long arr[],int n)
    {
        vector<long long>ans(n);
	    stack<long long>s;
    	s.push(-1);
    for(int i=0;i<n;i++)
    {
	    while(s.top()!=-1 && arr[s.top()] >= arr[i]) //we don't have
	                     //arr[-1] , that's why writing s.top()!=-1
	     {
		     s.pop();
	     }
	    ans[i]=s.top();
	     s.push(i);
 
     }
    return ans;
        
    }
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {vector< long long>next(n);
     next = nextSmallerElement(arr,n);
     vector< long long>prev(n);
     prev = prevSmallerElement(arr,n);
     long long ans=INT_MIN;
     for(int i=0;i<n;i++)
     {long long length = arr[i];
      if(next[i]==-1)
      {next[i]=n;}
      long long width = next[i]-prev[i]-1;
      long long area = length*width;
      ans = max(ans,area);
         
     }
     return ans;
        
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends