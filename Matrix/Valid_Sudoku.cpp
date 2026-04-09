#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int boardSize = board.size();

        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                else
                {
                    if (isValid(board, boardSize, board[i][j], i, j))
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool isValid(vector<vector<char>> &board, int boardSize, int value, int row, int col)
    {
        for (int i = 0; i < boardSize; i++)
        {
            if (col != i && board[row][i] == value)
            {
                return false;
            }
            if (row != i && board[i][col] == value)
            {
                return false;
            }
        }

        int squareSize = sqrt(boardSize);
        int sqrRowStart = row - row % squareSize;
        int sqrColStart = col - col % squareSize;

        for (int i = sqrRowStart; i < sqrRowStart + squareSize; i++)
        {
            for (int j = sqrColStart; j < sqrColStart + squareSize; j++)
            {
                if (i != row && j != col && board[i][j] == value)
                {
                    return false;
                }
            }
        }

        return true;
    }

    void print(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solution.print(board);

    return 0;
}

// https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150