//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        stack<int>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {char ch=s[i];
         if(ch=='(' || ch=='+'|| ch=='-' || ch=='*' || 
            ch=='/')
            {st.push(ch);}
            
         else if(ch==')')
            {
             bool flag=1;
             while(st.top() != '(')
             { char num=st.top();
                 if((num=='+'|| num=='-' || num=='*' || 
              num=='/'))
             {st.pop();
              flag =0;
             }
             }
             if(flag==1)
             {return 1;}
             st.pop();
            }
        }
       
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends