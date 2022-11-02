//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
bool solve(string s,int index,set<string>st)
    {if(index==s.length())
    {return true;}
     string subString="";
     for(int i=index;i<s.length();i++)
     {subString.push_back(s[i]);
     if(st.count(subString))
     {bool ans=solve(s,i+1,st);
     if(ans)
     {return true;}}
     }
     return false;
        
    }
    int wordBreak(string A, vector<string> &B) {
          set<string>st;
        for(auto it:B)
        {st.insert(it);}
        bool ans=solve(A,0,st);
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
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends