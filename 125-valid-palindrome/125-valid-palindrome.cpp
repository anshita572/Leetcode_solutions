class Solution {
public:
    char toLowercase(char ch)
{
if(ch>='a' && ch<='z') //i.e. ch is lowercase
{return ch;}
else //if(ch>='A' && ch<='Z')//i.e. ch is uppercase
{
    ch = ch- 'A'+'a'; //coverting uppercase to lowercase
    return ch;
}
}
    bool isPalindrome(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;
        while(i<=j)
        { if(isalnum(s[i])==0)
           {i++;}
            else if(isalnum(s[j])==0)
           {j--;}
          else if (toLowercase(s[i])!=toLowercase(s[j]))
            {return false;}
            else //if(s[i]==s[j])
            {i++;
            j--;}
          
           
        }
        return true;
    }
};