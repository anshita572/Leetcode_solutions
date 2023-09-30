//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
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
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        vector<vector<int>>ans;
         vector<int>temp;
         sort(arr.begin(),arr.end());
         solve(arr,0,temp,ans);
         return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends