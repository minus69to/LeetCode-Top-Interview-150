#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int nRow = board.size();
        int nCol = board[0].size();

        for (int j = 0; j < nCol; j++)
        {
            if (board[0][j] == 'O')
            {
                bfs(board, 0, j);
            }
            if (board[nRow - 1][j] == 'O')
            {
                bfs(board, nRow - 1, j);
            }
        }

        for (int i = 0; i < nRow; i++)
        {
            if (board[i][0] == 'O')
            {
                bfs(board, i, 0);
            }
            if (board[i][nCol - 1] == 'O')
            {
                bfs(board, i, nCol - 1);
            }
        }

        for (int i = 0; i < nRow; i++)
        {
            for (int j = 0; j < nCol; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }

        // print(board);
    }

    void bfs(vector<vector<char>> &grid, int row, int col)
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = '#';

        while (!q.empty())
        {
            pair<int, int> current = q.front();
            q.pop();

            int currentRow = current.first;
            int currentCol = current.second;

            vector<int> dRow = {0, -1, 0, 1};
            vector<int> dCol = {-1, 0, 1, 0};

            for (int i = 0; i < 4; i++)
            {
                int newRow = currentRow + dRow[i];
                int newCol = currentCol + dCol[i];

                if ((newRow >= 0 && newRow < grid.size()) && (newCol >= 0 && newCol < grid[0].size()) && (grid[newRow][newCol] == 'O'))
                {
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = '#';
                }
            }
        }
    }

    void print(vector<vector<char>> &board)
    {
        for (auto row : board)
        {
            for (auto cell : row)
            {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'O'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'X', 'X'}};
    solution.solve(board);

    return 0;
}

// https://leetcode.com/problems/surrounded-regions/description/?envType=study-plan-v2&envId=top-interview-150