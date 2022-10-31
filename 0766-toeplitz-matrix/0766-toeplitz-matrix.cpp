class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rowSize=matrix.size();
        int colSize=matrix[0].size();
        for(int i=1;i<rowSize;i++)
        {
            for(int j=1;j<colSize;j++)
            {if(matrix[i][j]!=matrix[i-1][j-1])
            {return false;}
            }
        }
        return true;
    }
};