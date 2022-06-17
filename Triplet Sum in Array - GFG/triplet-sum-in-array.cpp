// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    
    
    bool find3Numbers(int A[], int n, int X)
    {
       sort(A,A+n);
        int i=0;
        
        for(int i=0;i<n-2;i++)
        {   int low=i+1;
            int high=n-1;
            int sum=X-A[i];
            if(i==0 ||(i>0 && A[i]!=A[i-1]))
            while(low<high)
            {
               if(A[low]+A[high]==sum)
               {
    
                   while(low<high && A[low]==A[low+1])
                   {low++;}
                   while(low<high && A[high]==A[high-1])
                   {high--;}
                   low++;
                   high--;
                   return true;
                   
               }
                else if(A[low]+A[high]<sum)
                {low++;}
                else
                {high--;}
            }
        }
                return false;
                
    }
       

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends