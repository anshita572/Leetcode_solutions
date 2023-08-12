//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int node,int vis[],stack<int>&st,vector<vector<int>>& adj){
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        if(!vis[it]){
	          dfs(it,vis,st,adj);
	        }
	    }
	    st.push(node);
	}
   	void dfs2(int node,int vis[],vector<vector<int>>& adj){
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        if(!vis[it]){
	          dfs2(it,vis,adj);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int>st;
        int vis[V] = {0};
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
         vector<vector<int>>adjT(V);
         for(int i = 0; i < V; i++){
             vis[i] = 0;
             for(auto it : adj[i]){
                 // i -> it , after reverse : it -> i
                 adjT[it].push_back(i);
             }
         }
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                dfs2(node,vis,adjT);
                scc++;
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends