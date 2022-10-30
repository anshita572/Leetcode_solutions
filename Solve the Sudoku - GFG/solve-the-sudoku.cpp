//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    bool isSafe(int board[N][N],int row,int col,int no)
    {
        for(int i=0;i<9;i++)
        {
            //row check
            if(board[row][i]==no)
            {return false;}
            //column check
             if(board[i][col]==no)
            {return false;}
            // 3 X 3 matrix check
            
            if(board[3*(row/3) + (i/3)][3*(col/3)+ (i%3)] == no)
            {return false;}

        }
        return true;
    }
    bool solve(int board[N][N])
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {if(board[i][j]==0)
            {
                for(int no=1;no<=9;no++)
                {
                    if(isSafe(board,i,j,no))
                    {  board[i][j]=no;
                        bool recursiveCall=solve(board);
                    if(recursiveCall==true)
                    {return true;}
                    else
                    {board[i][j]=0;}
                    }
                }
                return false;
            }}
        }
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        solve(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        SolveSudoku(grid);
        for(int i=0;i<N;i++)
        {for(int j=0;j<N;j++)
            {cout<<grid[i][j]<<" ";}
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends