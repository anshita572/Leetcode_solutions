//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void dfs(int node,int parent,vector<int>adj[],int vis[],int timer,
            int tin[],int low[],vector<vector<int>>&ans){
                vis[node] = 1;
                tin[node] = low[node] = timer;
                timer++;
                for(auto it : adj[node]){
                    if(it == parent){
                        continue;
                    }
                    if(!vis[it]){
                        dfs(it,node,adj,vis,timer,tin,low,ans);
                        low[node] = min(low[node], low[it]);
                        if(low[it] > tin[node]){
                            vector<int>res;
                            res.push_back(node);
                            res.push_back(it);
                            sort(res.begin(),res.end());
                            ans.push_back(res);
                        }
                    }
                    else // if visited
                    {
                       low[node] = min(low[node], low[it]); 
                    }
                }
            }
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    vector<vector<int>>ans;
        int timer = 0;
        int vis[V] = {0};
        int tin[V];  // time of insertion
        int low[V]; //  lowest possible time to reach
        dfs(0,-1,adj,vis,timer,tin,low,ans);
        sort(ans.begin(),ans.end());
        return ans; 
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends