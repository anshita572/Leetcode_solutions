//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int solveSO(int nums[],int n)
{
int next1=0;
int next2=0;
int curr=0;
for(int i=n-1;i>=0;i--)
{int inc=nums[i]+next2;
int exc=next1;
curr=max(inc,exc);
next2=next1;
next1=curr;
}
return curr;
}
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
       return solveSO(arr,n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends