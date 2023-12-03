#include<bits/stdc++.h>
using namespace std;
int board[100][100];
int n;
bool isSafe(int row,int col)
{
    for(int i=0;i<col;i++)
    {
        if(board[row][i])
        {
            return false;
        }
    }
    for(int i=row,j=col;i<n && j>=0;i++,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    return true;
}
bool Solve(int col)
{
    if(col>=n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(i,col))
        {
            board[i][col]=1;
            if(Solve(col+1))
            {
                
            }
            board[i][col]=0;
        }
    }
    return false;
}
int main()
{
    cin>>n;
    if(Solve(0))
    {
        
    }
}