#include <stdio.h>
#define UNASSIGNED 0
#define N 9
#define true 1
#define false 0

int r=0,c=0;
int SolveSudoku(int grid[N][N])
{
    int row, col,num;
 

    if (!FindUnassignedLocation(grid, row, col))
       return true; 
 
    row=r;
    col=c;
   
    for (num = 1; num <= 9; num++)
    {
     
        if (isSafe(grid, row, col, num))
        {
          
            grid[row][col] = num;
 
           
            if (SolveSudoku(grid))
                return true;
 
          
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

int FindUnassignedLocation(int grid[N][N], int row, int col)
{
    r=row;
    c=col;
    for (r = 0; r < N; r++)
        for (c = 0; c < N; c++)
            if (grid[r][c] == UNASSIGNED)
                return true;
    return false;
}
 
int UsedInRow(int grid[N][N], int row, int num)
{
   int col;
    for ( col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
int UsedInCol(int grid[N][N], int col, int num)
{
    int row;
    for ( row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
int UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
   int row,col;
    for (row = 0; row < 3; row++)
        for (col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}
 
int isSafe(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row%3 , col - col%3, num);
}
 
void printGrid(int grid[N][N])
{
   int row,col;
    for ( row = 0; row < N; row++)
    {
       for (col = 0; col < N; col++)
             printf("%2d", grid[row][col]);
        printf("\n");
    }
}
 
int main()
{
    int i,j,grid[N][N];
    printf("Enter the sudoku and enter 0 for unassigned cells\n");
    
    for(i=0; i<N ;i++){
      for(j=0; j<N ;j++)
        scanf("%d",&grid[i][j]);
     }
    printf("\n");
    if (SolveSudoku(grid) == true)
          printGrid(grid);
    else
         printf("No solution exists");
 
    return 0;
}
