#include <stdio.h>

int board[20][20]={0};

void print(int board[20][20],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",board[i][j]);
        printf("\n");
    }
}

int check(int board[20][20],int row,int col,int n)
{
    int i,j;
    for (i = 0; i < col; i++)
    if (board[row][i])
        return 0;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return 0;
    return 1;
}

int solve(int board[20][20],int n,int col)
{
    int i,j;
    if (col >= n)
        return 1;
    for (int i = 0; i < n; i++) 
    {
        if (check(board, i, col,n)) 
        {
        board[i][col] = 1;
        if (solve(board,n, col + 1))
        return 1;
        board[i][col] = 0;
        }
    }
    return 0;
}

int main()
{
    int n,i,j;
    printf("Enter number of queens to place:\n");
    scanf("%d",&n);
    
    int ans=solve(board,n,0);
    if(!ans)
    {
        printf("Could not place all queens\n");
    }
    else
    {
        printf("The board placement is:\n");
        print(board,n);
    }
}