// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long count=0;
    void merge(long long arr[],long long start,long long end)
{   long long mid=start+(end-start)/2;
    long long n1=mid-start+1;  //n1 : length of first subarray
     long long n2=end-mid;     //n2 : length of second subarray
     long long subArray1[n1]; 
    long long subArray2[n2];
//copying values from arr to subArray1
long long k=start;
for(long long i=0;i<n1;i++)
{
    subArray1[i]=arr[k++];
}
//copying values from arr to subArray2
 k=mid+1;
for(long long j=0;j<n2;j++)
{
    subArray2[j]=arr[k++];
}
//merging and sorting the 2 subarrays
long long i=0;     //i : index for subArray1
long long j=0;    //j : index for subArray2
k=start;    //k : index for arr i.e. which is our main array
while(i<n1 && j<n2)
{if(subArray1[i]<=subArray2[j])
{
    arr[k++]=subArray1[i++];
}
else       //if(subArray2[j]<subArray1[i])
{
    arr[k++]=subArray2[j++];
    count=count+ n1-i;
}
}
if(i>n1)//subArray1 is finished but some elements of 
//subArray2 are still remaining,so copy those elements of
//subArray2 in arr
{
    while(j<n2)
    {
      arr[k++]=subArray2[j++];
    }
}
else      //(j>n2)
//subArray2 is finished but some elements of 
//subArray1 are still remaining,so copy those elements of
//subArray1 in arr
{
    while(i<n1)
    {
      arr[k++]=subArray1[i++];
    }
}

}

void mergeSort(long long arr[],long long start,long long end)
{//base case
    if(start>=end)
    {return;}
long long mid=start+(end-start)/2;
    
    //else (start,end)
    mergeSort(arr,start,mid);//recursive call
    mergeSort(arr,mid+1,end);//recursive call
    merge(arr,start,end);//calling merge function
}
    long long int inversionCount(long long arr[], long long N)
    { count=0;
        mergeSort(arr,0,N-1);
        return count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends