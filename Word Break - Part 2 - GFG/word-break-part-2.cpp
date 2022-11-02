//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void solve(string s,int index,unordered_set<string>st,string &temp,  vector<string>&ans)
    {
        //base case
        if(index==s.length())
        {
            temp.pop_back();
        ans.push_back(temp);
        return;}
        string subString="";
        for(int i=index;i<s.length();i++)
        {
            subString.push_back(s[i]);
            if(st.count(subString))
            {string old_temp=temp;
                temp=temp+subString+" ";
                 solve(s,i+1,st,temp,ans);//recursive call
               temp=old_temp; //backtrack
            }
          
            
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
       unordered_set<string>st;
        for(auto it:dict)
        {st.insert(it);}
        string temp="";
         vector<string>ans;
        solve(s,0,st,temp,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends