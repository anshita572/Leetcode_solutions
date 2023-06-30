//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<int> nextSmallerElement(int arr[],int n)
    {
        vector<int>ans(n);
	    stack<int>s;
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
    vector<int> prevSmallerElement(int arr[],int n)
    {
        vector<int>ans(n);
	    stack<int>s;
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
    int getMaxArea(int arr[], int n)
    {vector<int>next(n);
     next = nextSmallerElement(arr,n);
     vector<int>prev(n);
     prev = prevSmallerElement(arr,n);
     int ans=INT_MIN;
     for(int i=0;i<n;i++)
     {int length = arr[i];
      if(next[i]==-1)
      {next[i]=n;}
      int width = next[i]-prev[i]-1;
      int area = length*width;
      ans = max(ans,area);
         
     }
     return ans;
        
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
     int area=getMaxArea(M[0],m);
     for(int i=1;i<n;i++)
     {for(int j=0;j<m;j++)
     {  if(M[i][j]!=0)
            {M[i][j] = M[i][j] + M[i-1][j];}
        else
            {M[i][j] = 0 ;}
         
     }
     area = max(area , getMaxArea(M[i],m));
         
     }
     return area;
    }
//     5 12
// 0 0 1 0 0 1 1 0 0 1 1 0
// 0 1 0 0 0 0 0 1 1 1 1 0
// 1 0 0 1 1 1 1 0 1 0 1 1
// 0 0 1 1 1 0 1 1 1 0 1 1
// 1 0 1 0 0 1 0 0 1 0 1 1
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends