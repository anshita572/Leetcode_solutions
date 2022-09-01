class Solution {
public:
    void solve(vector<char>& s,int l,int h)
    {
        if(l>h)
        {return;}
        swap(s[l],s[h]);
        solve(s,l+1,h-1);
    }
    void reverseString(vector<char>& s) {
        solve(s,0,s.size()-1);
    }
};