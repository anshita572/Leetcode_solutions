//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {int n1=m-l+1;
int n2=r-m;
int left[n1];
int right[n2];
int j=0;
for(int i=l;i<=m;i++)
{left[j]=arr[i];
j++;}
int k=0;
for(int i=m+1;i<=r;i++)
{right[k]=arr[i];
k++;}
int index=l;
int x=0;
int y=0;
while(x<n1 && y<n2)
{if(left[x]<right[y])
{arr[index]=left[x];
x++;
index++;}
else
{arr[index]=right[y];
y++;
index++;}
}
while(x<n1)
{arr[index]=left[x];
x++;
index++;}
while(y<n2)
{arr[index]=right[y];
y++;
index++;}

        
    }
    void mergeSort(int arr[], int l, int r)
{//base case
if(l>=r)
{return;}
int mid=l+(r-l)/2;
mergeSort(arr,l,mid); //left part
mergeSort(arr,mid+1,r); //right part
merge(arr,l,mid,r);
        
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends