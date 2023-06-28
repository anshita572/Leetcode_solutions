//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    int n=s.size();
    if(n%2 == 1) 
    {return -1;}
    int open=0;
    int close=0;
    for(int i=0;i<n;i++)
    {if(s[i]=='{')
     {open++;}
     else
       if(open==0)
       {close++;}
       else
       {open--;}
        
    }
    int count = (open+1)/2 + (close+1)/2;
    return count;
}