class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      //Constraints: m == matrix.length and n == matrix[i].length (given in ques)
        
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=i+1;j<col;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
      for(int i=0;i<row;i++)
      { int k=col-1;
       int j=0;
          while(j<=k)
          {
              swap(matrix[i][j],matrix[i][k]);
              j++;
              k--;
          }
      }
    }
};