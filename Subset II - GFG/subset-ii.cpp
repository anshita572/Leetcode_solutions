//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
  void solve(vector<int>& nums, int i, vector<int>&temp,
    vector<vector<int>>&ans){
        ans.push_back(temp);
        for(int j = i; j < nums.size(); j++){
            if(j != i && nums[j] == nums[j-1]){
                continue;
            }
            temp.push_back(nums[j]);
            solve(nums,j+1,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        vector<vector<int>>ans;
         vector<int>temp;
         sort(nums.begin(),nums.end());
         solve(nums,0,temp,ans);
         return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends