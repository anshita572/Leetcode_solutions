//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
     void solve(int currOpen,int currClose,int remOpen,
    int remClose,string &temp,vector<string>&ans)
    {
        //base case
        if(remOpen==0 && remClose==0)
        {ans.push_back(temp);
        return;}
        if(remOpen > 0)
        {
            temp.push_back('(');
            solve(currOpen+1,currClose,remOpen-1,remClose,temp,ans);
            temp.pop_back();
        }
         if(remClose > 0  && currOpen > currClose)
        {
            temp.push_back(')');
            solve(currOpen,currClose+1,remOpen,remClose-1,temp,ans);
        temp.pop_back(); }
        
    }
    vector<string> AllParenthesis(int n) 
    {
         vector<string>ans;
        string temp="(";
        int currOpen=1;
        int currClose=0;
        int remOpen=n-1;
        int remClose=n;
        solve(currOpen,currClose,remOpen,remClose,temp,ans);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends