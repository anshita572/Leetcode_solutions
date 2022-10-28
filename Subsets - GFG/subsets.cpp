//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void solve(vector<int>& nums,int i, vector<int>&temp,
    vector<vector<int>>&ans)
    {
        if(i>=nums.size())
        {ans.push_back(temp);
        return;}
        //include
        temp.push_back(nums[i]);
        solve(nums,i+1,temp,ans);
        temp.pop_back();//backtrack
        //exclude
        solve(nums,i+1,temp,ans);
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
         vector<vector<int>>ans;
         vector<int>temp;
         solve(A,0,temp,ans);
         sort(ans.begin(),ans.end());
         return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends