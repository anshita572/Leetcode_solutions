class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n=arr.size();
    unordered_map<int,int>m;
       int x=n/3;
       vector<int>ans;
        int count=0;
       for(int i=0;i<n;i++)
       {m[arr[i]]++;}
       for(auto i:m)
       {
           if(i.second > x)
           {ans.push_back(i.first);}
       }
     
        return ans;
    }
};