// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int difference=arr[n-1]-arr[0];
        int smallest=arr[0]+k; //sbme 'k' add krne k baad arr[0] will be the smallest
        int largest=arr[n-1]-k;//sbme 'k' subtract krne k baad arr[n-1] will be the largest
        int mini,maxi;
        for(int i=0;i<n-1;i++)
        {
            mini=min(smallest,arr[i+1]-k);
            maxi=max(largest,arr[i]+k);
            if(mini < 0)
            {continue;}
            difference=min(difference,(maxi-mini));
        }
        return difference;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends