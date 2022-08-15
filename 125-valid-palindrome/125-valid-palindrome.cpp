class Solution {
public:
    
    bool isPalindrome(string s) {
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {s[i]=s[i]-'A'+'a';}
        }
        int i=0;
        int j=n-1;
        while(i<=j)
        { if(isalnum(s[i])==0)
           {i++;}
            else if(isalnum(s[j])==0)
           {j--;}
          else if (s[i]!=s[j])
            {return false;}
            else //if(s[i]==s[j])
            {i++;
            j--;}
          
           
        }
        return true;
    }
};