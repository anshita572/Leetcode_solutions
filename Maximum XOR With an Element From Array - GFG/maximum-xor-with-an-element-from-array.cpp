//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    struct Node{
    Node*links[2]; // size = 2 (for 0 and 1)
    bool containsKey(int bit){
        if(links[bit] != NULL){
            return true;
        }
        return false;
    }

    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node*node){
        links[bit] = node;
    }
};
class Trie{
    private: 
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
   
        void insert(int num){
            Node* node = root;
            // start inserting or checking from 32nd bit (31st index)
            for(int i = 31; i >= 0; i--){
                 // check if bit is set or not i.e 1 or 0
                int bit = (num >> i) & 1;
                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }
                node = node->get(bit);
            }
        }
        int getMax(int x){
            Node* node = root;
            int maxi = 0;
            for(int i = 31; i >= 0; i--){
            
            int bit = (x >> i) & 1;
            if(node->containsKey(!bit)) // for max , we want opposite bit
            {
                maxi = maxi | (1 << i);
                node = node->get(!bit);
            }
            else{
                node = node->get(bit);
             }
            }
            return maxi;
        }
};
    vector<long long> maximumXor(int N, int Q, vector<int> &arr,
                                 vector<vector<int>> &queries) {
      sort(arr.begin(),arr.end());
      vector<long long>ans(Q,0);
      vector<pair<int,pair<int,int>>>q;
      for(int i = 0; i < Q; i++){
          q.push_back({queries[i][1],{queries[i][0],i}});
      }
      sort(q.begin(),q.end());
      int index = 0;
      Trie trie;
      for(int i = 0; i < Q; i++){
          int ai = q[i].first;
          int x = q[i].second.first;
          int qi = q[i].second.second;
          while(index < N && arr[index] <= ai){
              trie.insert(arr[index]);
              index++;
          }
          if(index != 0){
              ans[qi] = trie.getMax(x);
          }
          else{
              ans[qi] = -1;
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, Q;
        cin >> N >> Q;
        vector<vector<int>> queries(Q, vector<int>(2));
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < Q; i++) {
            cin >> queries[i][0] >> queries[i][1];
        }
        Solution obj;
        vector<long long> ans = obj.maximumXor(N, Q, arr, queries);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends