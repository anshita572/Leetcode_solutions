class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rowSize=matrix.size();
        int colSize=matrix[0].size();
        for(int i=0;i<rowSize-1;i++)
        {
            for(int j=0;j<colSize-1;j++)
            {if(matrix[i][j]!=matrix[i+1][j+1])
            {return false;}
            }
        }
        return true;
    }
};