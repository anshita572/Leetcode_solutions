class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++)
        { for(int j=i+1;j<col;j++)
        {swap(matrix[i][j],matrix[j][i]);}
        }
        //reverse
        
        for(int i=0;i<row;i++)
        { int start=0;
          int end=col-1;
          while(start <= end)
          {swap(matrix[i][start],matrix[i][end]);
          start++;
          end--;}
            
        }
    }
};