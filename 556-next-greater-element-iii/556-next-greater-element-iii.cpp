class Solution {
public:
    int nextGreaterElement(int num) {
        string s=to_string(num);
      int n=s.size();
        int i,j;
        for(i=n-2;i>=0;i--)
        {
            if(s[i]<s[i+1])
            {break;}
        }
        if(i<0) //if no breakpoint found ,e.g. 3,2,1 ;ans will be -1
        {return -1;}
        else //if breakpoint found
        {
            for(j=n-1;j>=0;j--)
            {
                if(s[j]>s[i])
                {break;}
            }
            swap(s[i],s[j]);
        reverse(s.begin()+i+1,s.end());}
       
        long long ans=stol(s);
        if(ans >INT_MAX || ans < INT_MIN)
        {return -1;}
        return ans;
        
    }
};