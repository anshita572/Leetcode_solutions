// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string s){
  
   // int n=A.length();
    int i,j;
    for(j=0;s[j]!='\0';j++)
    {}
    j=j-1;
    for(i=0;i<j;i++,j--)
    {
        swap(s[i],s[j]);
    }
   cout<<s;
}