class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n=s.size();
        sort(s.begin(),s.end());
        string a=s[0];
        string b=s[n-1];
        string ans="";
        for(int i=0;i<a.length();i++)
        {
            if(a[i]==b[i])
            {ans+=a[i];}
            else
            {break;} //i.e not found ,return empty string
        }
        return ans;
    }
};