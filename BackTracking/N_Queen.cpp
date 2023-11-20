#include <bits/stdc++.h>
using namespace std;
int n;
int board[10][10];
bool isSafe(int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}
bool solveNQueens(int col)
{
    if (col >= n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 1;

            if (solveNQueens(col + 1))
            {
                return true;
            }

            board[i][col] = 0; // Backtrack
        }
    }
    return false;
}
void printBoard()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter the number of queens: ";
    cin >> n;
    if (solveNQueens(0))
    {
        cout << "Solution found:" << endl;
        printBoard();
    }
    else
    {
        cout << "No solution exists for " << n << " queens." << endl;
    }

    return 0;
}
