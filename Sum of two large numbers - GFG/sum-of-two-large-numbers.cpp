//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // void solve(string num1, string num2,int i,int j,int carry,string &ans)
    // {
    //     if(i<0 && j<0 && carry==0)
    //     {return;}
    //     int first=0;
    //     int second=0;
    //     if(i>=0)
    //     {  first=num1[i]-'0';}
    //     if(j>=0)
    //     {second=num2[j]-'0';}
    //     int sum=first+second+carry;
    //     int last_dig=sum % 10;
    //     carry=sum/10;
    //     solve(num1,num2,i-1,j-1,carry,ans);
    //     ans=ans+to_string(last_dig);
        

    // }
    string findSum(string X, string Y) {
        
        int i=X.length()-1;
        int j=Y.length()-1;
       string ans;
       int carry=0;
        // solve(X,Y,i,j,0,ans);
       
       
        while(i>=0 || j>=0 || carry !=0)
       {   int first=0;
        int second=0;
           if(i>=0)
        {  first=X[i]-'0';}
        if(j>=0)
        {second=Y[j]-'0';}
           int sum=first+second+carry;
        int last_dig=sum % 10;
        carry=sum/10;
        ans=ans+to_string(last_dig);
           i--;
           j--;
       }
       reverse(ans.begin(),ans.end());
        while(ans[0]=='0' && ans.size()>1)
        {ans.erase(ans.begin());}
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends