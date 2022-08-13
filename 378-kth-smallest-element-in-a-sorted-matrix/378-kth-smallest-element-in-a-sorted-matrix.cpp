class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat[0].size();
        vector<int>temp;
    for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          temp.push_back(mat[i][j]);
      }
  }
  sort(temp.begin(),temp.end());
  int ans=temp[k-1];
  return ans;
    }
};