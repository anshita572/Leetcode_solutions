class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,int no)
    {
        for(int i=0;i<9;i++)
        {
            //row check
            if(board[row][i]==no+'0') //converting int to char
            {return false;}
            //column check
             if(board[i][col]==no+'0')
            {return false;}
            // 3 X 3 matrix check
            
            if(board[3*(row/3) + (i/3)][3*(col/3)+ (i%3)] == no + '0')
            {return false;}

        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {if(board[i][j]=='.')
              {
                for(int no=1;no<=9;no++)
                {
                    if(isSafe(board,i,j,no))
                    {  board[i][j]=no+'0'; //converting int to char
                        bool recursiveCall=solve(board);
                    if(recursiveCall==true)
                    {return true;}
                    // else
                    // {board[i][j]='.';}
                    }
                }
                board[i][j]='.';
                return false;
             }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};