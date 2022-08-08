class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int count=0;
        int row=matrix.size();
        int col=matrix[0].size();
        int n=row*col; //total no of elements in matrix
        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;
        while(count<n)
        {
            //starting row print
            for(int i=startingCol;i<=endingCol && count<n;i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            //ending Col print
            for(int i=startingRow;i<=endingRow && count < n;i++)
            {ans.push_back(matrix[i][endingCol]);
             count++;}
            endingCol--;
            //ending Row print
            for(int i=endingCol;i>=startingCol  && count < n;i--)
            {ans.push_back(matrix[endingRow][i]);
             count++;}
            endingRow--;
            //starting col print
            for(int i=endingRow;i>=startingRow  && count < n;i--)
            {
                ans.push_back(matrix[i][startingCol]);
                 count++;
            }
            startingCol++;
        }
        return ans;
    }
};