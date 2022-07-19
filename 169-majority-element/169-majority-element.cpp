class Solution {
public:
    int majorityElement(vector<int>& arr) {
         int n=arr.size();
         unordered_map<int,int>m;
       int x=n/2;
       int ans;
       for(int i=0;i<n;i++)
       {m[arr[i]]++;}
       for(auto i:m)
       {
           if(i.second > x)
           {ans=i.first;}
       }
     
        return ans;
    }
};