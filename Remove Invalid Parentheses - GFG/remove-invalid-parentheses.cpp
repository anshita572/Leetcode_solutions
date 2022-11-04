//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  int removeCount(string s)
    {
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='(')
            {st.push('(');}
            else if(ch==')')  //writing else if and not just else beacause else would mean ')' and alphabets 
            {if(!st.empty() && st.top()=='(')
            {st.pop();}
            else
            {st.push(')');}
            }
        }
        return st.size();
        
    }
    void solve(string s,int invalid_count,map<string,bool>&mp,  vector<string>&ans)
    {
        //base case
        //koi valid string ka combination repeat kr rha i.e. already present in map so no need to print repeatedly 
        if(mp[s]==true) 
        {return;}
        else
        {mp[s]=true;} //nhi present map m toh daal do usko map k
        if(invalid_count==0)
        {
            int cnt=removeCount(s);
            if(cnt==0)
            {ans.push_back(s);}
             return;
        }
        for(int i=0;i<s.length();i++)
        {
            string leftStr=s.substr(0,i);
            string rightStr=s.substr(i+1);
            string temp=leftStr+rightStr;
            solve(temp,invalid_count-1,mp,ans);
        }
        
    }
    vector<string> removeInvalidParentheses(string s) {
         int invalid_count=removeCount(s);
        // cout<<invalid_count;
        vector<string>ans;
        map<string,bool>mp;
        solve(s,invalid_count,mp,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends