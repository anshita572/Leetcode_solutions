//{ Driver Code Starts


#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:

	
	bool checkDuplicatesWithinK(int arr[], int n, int k) {
	     unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.count(arr[i]))
            {if((i-mp[arr[i]])<=k)
            {return true;}
            }
            
            mp[arr[i]]=i;
        }
        return false;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkDuplicatesWithinK(arr, n, k);
        if(ans){
            cout<<"True\n";
        }else{
            cout<<"False\n";
        }
    }
    return 0;
}
// } Driver Code Ends