class Solution {
public:
    void solve(string num1, string num2,int i,int j,int carry,string &ans)
    {
        if(i<0 && j<0 && carry==0)
        {return;}
        int first=0;
        int second=0;
        if(i>=0)
        {  first=num1[i]-'0';}
        if(j>=0)
        {second=num2[j]-'0';}
        int sum=first+second+carry;
        int last_dig=sum % 10;
        carry=sum/10;
        solve(num1,num2,i-1,j-1,carry,ans);
        ans=ans+to_string(last_dig);
        

    }
    string addStrings(string num1, string num2) {
        int i=num1.length()-1;
        int j=num2.length()-1;
       string ans;
        solve(num1,num2,i,j,0,ans);
        
        
        return ans;
    }
};