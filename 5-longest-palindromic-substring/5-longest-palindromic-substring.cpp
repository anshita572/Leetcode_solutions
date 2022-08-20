class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        int maxi=0;
        int start_index=0;
        for(int i=1;i<n;i++)
        {
            //odd length palindrome
            int low=i-1;
            int high=i+1;
            while(low>=0 && high<n && s[low]==s[high])
            {
                if(high-low+1 > maxi)
                {maxi=high-low+1;
                start_index=low;}
                low--;
                high++;
            }
             //even length palindrome
             low=i-1;
             high=i;
            while(low>=0 && high<n && s[low]==s[high])
            {
                if(high-low+1 > maxi)
                {maxi=high-low+1;
                 start_index=low;}
                low--;
                high++;
            }
        }
        // if(maxi==0)
        // {ans=s[0];}
        // for(int i=start_index;i<start_index+maxi;i++)
        // {ans+=s[i];}
        // return ans;
         
        if(maxi==0)
        {  s=s[0];
            return s;}
        return s.substr(start_index,maxi);
        
    }
};