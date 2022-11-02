class Solution {
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
                // solve(s,i+1,st,temp+subString+" ",ans);
                 solve(s,i+1,st,temp,ans);
               temp=old_temp;
            }
          
            
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto it:wordDict)
        {st.insert(it);}
        string temp="";
         vector<string>ans;
        solve(s,0,st,temp,ans);
        return ans;
    }
};