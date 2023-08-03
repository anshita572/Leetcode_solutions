//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node, vector<int>adj[],int color[],int curr_color){
        color[node] = curr_color;
        for(auto i : adj[node]){
            if(color[i] == -1){
               if (dfs(i,adj,color,!curr_color)==false)
               {return false;}
            }
            else if(color[i] == curr_color)
            {return false;}
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	   // vector<int>color (V,-1);
	   int color[V];
	   for(int i=0;i<V;i++)
	    {color[i]=-1;}
	    int curr_color = 0;
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	          if(dfs(i,adj,color,curr_color) == false)
	            {return false;}
	        }
	    }
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends