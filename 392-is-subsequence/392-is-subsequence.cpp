class Solution {
public:
    void solve(string s, string t,int i,int j,int& count)
    {
        if(j==t.length())
        {return;}
        if(s[i]==t[j])
        {count++;
            solve(s,t,i+1,j+1,count);}
        else //if(s[i]!=t[j])
        {solve(s,t,i,j+1,count);}
    }
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        int count=0;
        solve(s,t,i,j,count);
        if(count==s.length())
        {return true;}
        else
        {return false;}
    }
};