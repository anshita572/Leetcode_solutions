class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int i=0;
        int j=col-1;
        while(i<row && j>=0)
        {int element=matrix[i][j];
        if(element==target)
        {return true;}
        else if(element < target)
        {i++;}
         else//if(element > target)
         {j--;}
        }
        return false;
    }
};