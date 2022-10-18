//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void solve(int i,string &S,vector<string>&ans)
	{if(i>=S.size())
	    {ans.push_back(S);
	        return;
	    }
	    for(int j=i;j<S.size();j++)
	    { if(j>i&& S[j]==S[j-1])continue;
	        swap(S[i],S[j]);
	        solve(i+1,S,ans);
	        swap(S[i],S[j]);
	    }
	}
	
		vector<string>find_permutation(string S)
		{vector<string>ans;
		solve(0,S,ans);
		sort(ans.begin(),ans.end());
		return ans;
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends