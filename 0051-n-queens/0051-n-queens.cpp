class Solution {
public:
    bool isSafe(vector<string>&board,int row,int col,int n)
    {//check straight movement
        int x=row;
        int y=col;
        while(y>=0)
        {if (board[x][y]=='Q')
        {return false;}
        y--;}
        //check upper diagonal
        x=row;
        y=col;
        while(x>=0 && y>=0)
        {if (board[x][y]=='Q')
        {return false;}
        x--;
        y--;}
        //check lower diagonal
        x=row;
        y=col;
        while(x<n && y>=0)
        {if (board[x][y]=='Q')
        {return false;}
        x++;
        y--;}
        return true;
        
    }
    void solve(int n,vector<string>&board,int col,          vector<vector<string>>&ans)
    {
        //base case
        if(col==n)
        {ans.push_back(board);
        return;}
        for(int row=0;row<n;row++)
        { if(isSafe(board,row,col,n))
        {board[row][col]='Q';
        solve(n,board,col+1,ans); //recursive call
         board[row][col]='.';}//backtrack
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {board[i].push_back('.');}
        }
        int col=0;
        solve(n,board,col,ans);
        return ans;
    }
};