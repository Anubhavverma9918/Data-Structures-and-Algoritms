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
    private:
    bool isValid(int grid[N][N], int row, int col, int& value) {
      for (int i = 0; i < N; i++) {
        if (grid[i][col] == value)
          return false;
    
        if (grid[row][i] == value)
          return false;
    
        if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value)
          return false;
      }
      return true;
    }
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < N; j++) {
          if (grid[i][j] == 0) {
            for (auto value = 1; value <= 9; value++) {
              if (isValid(grid, i, j,value)) {
                grid[i][j] = value;
    
                if (SolveSudoku(grid))
                  return true;
                else
                  grid[i][j] = 0;
              }
            }
    
            return false;
          }
        }
      }
      return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(auto i= 0; i<N; i++){
          for(auto j=0; j<N; j++){
            cout<<grid[i][j]<<" ";
          }
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