//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
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
class Solution
{
    public:
    int max_xor(int arr[] , int n)
    {
    Trie trie;
    for(int i = 0; i < n; i++){
        trie.insert(arr[i]);
    } 
    int maxi = 0;
   for(int i = 0; i < n; i++){
       maxi = max(maxi, trie.getMax(arr[i]));
   }
    return maxi;
        
    }
    
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}



// } Driver Code Ends