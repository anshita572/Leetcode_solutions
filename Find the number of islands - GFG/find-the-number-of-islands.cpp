//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void bfs(int row,int col, vector<vector<int>>&vis,  vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        vis[row][col] = 1;
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int n_row = row + i; //neighbour_row
                    int n_col = col + j; // neighbour_col
                    if(n_row>=0 && n_row<n && n_col>=0 &&
                    n_col<m && !vis[n_row][n_col] &&
                    grid[n_row][n_col]=='1'){
                        q.push({n_row,n_col});
                        vis[n_row][n_col] = 1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        vector<vector<int>>vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends