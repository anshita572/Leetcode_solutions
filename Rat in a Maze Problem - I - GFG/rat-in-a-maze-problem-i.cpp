//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int i,int j, vector<vector<int>>&vis, 
    int n, vector<vector<int>> &m){
        if(i>=0 && i < n && j>=0 && j < n && m[i][j] == 1 && 
        vis[i][j] == 0){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &m, int n, 
    vector<vector<int>>&vis, vector<string>&ans,string &path,
    int i,int j){
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        // down
        int x1 = i+1;
        int y1 = j;
        if(isSafe(x1,y1,vis,n,m)){
            vis[i][j] = 1;
            path.push_back('D');
            solve(m,n,vis,ans,path,x1,y1);
            vis[i][j] = 0;
            path.pop_back();
        }
        // up
        x1 = i-1;
        y1 = j;
        if(isSafe(x1,y1,vis,n,m)){
            vis[i][j] = 1;
            path.push_back('U');
            solve(m,n,vis,ans,path,x1,y1);
            vis[i][j] = 0;
            path.pop_back();
        }
        // right
        x1 = i;
        y1 = j+1;
        if(isSafe(x1,y1,vis,n,m)){
            vis[i][j] = 1;
            path.push_back('R');
            solve(m,n,vis,ans,path,x1,y1);
            vis[i][j] = 0;
            path.pop_back();
        }
        // left
        x1 = i;
        y1 = j-1;
        if(isSafe(x1,y1,vis,n,m)){
            vis[i][j] = 1;
            path.push_back('L');
            solve(m,n,vis,ans,path,x1,y1);
            vis[i][j] = 0;
            path.pop_back();
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string path = "";
         vector<string>ans;
        if(m[0][0] == 0){
            return ans;
        }
        vector<vector<int>>vis(n,vector<int>(n,0));
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         vis[i][j] = 0;
        //     }
        // }
        solve(m,n,vis,ans,path,0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends