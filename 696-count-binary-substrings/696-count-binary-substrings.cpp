class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.length();
        vector<int>v(n);
        int index=0;
        v[index]=1;
        for(int i=1;i<n;i++)
        {if(s[i]!=s[i-1])
        {index++;
        v[index]=1;}
         else
         {v[index]++;}
            
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {ans+=min(v[i],v[i-1]);}
        return ans;
        
    }
};