class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int count=0;
        for(int i=0;i<s.length();i++)
        {char ch=s[i];
         if(ch=='[')
         {st.push(ch);}
         else //if(ch==']')
         {
             if(!st.empty())
             {st.pop();}
             else //
             {count++;}
         }
            
        }
        int ans=(count+1)/2;
        return ans;
    }
};