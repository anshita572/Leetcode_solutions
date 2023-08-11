//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int node,int parent,int timer,int vis[],int tin[],int low[],
    int marked[],vector<int>adj[]){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it : adj[node]){
            if(it == parent){
                continue;
            }
            if(!vis[it]){
                dfs(it,node,timer,vis,tin,low,marked,adj);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && parent != -1){
                    marked[node] = 1;
                }
                child++;
            }
            else // if not visited
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if(child > 1 && parent == -1){
                marked[node] = 1;
            }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
       int timer = 0;
       int vis[V] = {0};
       int tin[V];
       int low[V];
       int marked[V]={0};
       vector<int>ans;
       for(int i = 0; i < V; i++){
           if(!vis[i]){
               dfs(i,-1,timer,vis,tin,low,marked,adj);
           }
       }
       for(int i = 0; i < V; i++){
           if(marked[i] == 1){
              ans.push_back(i);
       }
       }
       
       if(ans.size() == 0){
           return {-1};
       }
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends