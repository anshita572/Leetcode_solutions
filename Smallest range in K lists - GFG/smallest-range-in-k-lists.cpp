//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class node{
public:
  int data;
  int row;
  int col;
  node(int d,int r,int c) //constructor
  {data=d;
  row=r;
  col=c;
  } 
};
class compare{
public:
 bool operator() (node *a,node*b)
 {return a->data > b->data;}
};
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {int mini=INT_MAX;
     int maxi=INT_MIN;
     priority_queue<node*,vector<node*>,compare>pq;
     for(int i=0;i<k;i++)
     {
       int element=KSortedArray[i][0];
       mini=min(mini,element);
      maxi=max(maxi,element);
      node*temp=new node(element,i,0);
      pq.push(temp);
     }
     int start=mini;
     int end=maxi;
     while(!pq.empty())
     { node*temp=pq.top();
       pq.pop();
       mini=temp->data;
       if(maxi-mini < end-start)
       {start=mini;
       end=maxi;}
       if(temp->col+1 < n)
       {maxi=max(maxi,KSortedArray[temp->row][temp->col+1]);
        node*temp1=new node(KSortedArray[temp->row][temp->col+1],temp->row,temp->col+1);
        pq.push(temp1);
       }
       else
       {break;}
     }
     return {start,end};
         
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends