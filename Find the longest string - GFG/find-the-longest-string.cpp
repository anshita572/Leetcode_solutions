//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
struct Node{
    Node* links[26];
    bool flag = false;
    bool containKey(char ch){
        if(links[ch - 'a'] != NULL){
            return true;
        }
        return false;
    }
    Node *get(char ch){
        return links[ch - 'a'];
    }
    void put(char ch,Node* node){
        links[ch - 'a'] = node;
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag; 
    }
    
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool checkIfAllPrefixExists(string word){
        Node* node = root;
        bool flag = false;
        for(int i = 0; i < word.size(); i++){
            if(node->containKey(word[i])){
                node = node->get(word[i]);
                if(node->isEnd() == false){
                    return false;
                }
            }
            else // if(!node->containKey(word[i]))
            {return false;}
        }
        return true;
    }
};
class Solution
{
public:
    string longestString(vector<string> &words)
    {Trie* obj = new Trie();
     for(auto it : words){
         obj->insert(it);
     }
     string ans = "";
     for(auto it : words){
         if(obj->checkIfAllPrefixExists(it)){
             if(it.size() > ans.size()){
                 ans = it;
             }
             else if (it.size() == ans.size() && it < ans){
                 ans = it;
             }
         }
     }
      return ans;
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
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends