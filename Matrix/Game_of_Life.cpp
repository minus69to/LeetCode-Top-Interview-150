#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                int liveNeighbours = countLiveNeighbours(board, i, j);

                if (board[i][j] % 2 == 1)
                {
                    if (liveNeighbours == 2 || liveNeighbours == 3)
                    {
                        board[i][j] += 2;
                    }
                }
                else
                {
                    if (liveNeighbours == 3)
                    {
                        board[i][j] += 2;
                    }
                }
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                board[i][j] /= 2;
            }
        }
    }

    int countLiveNeighbours(vector<vector<int>> &board, int r, int c)
    {
        int m = board.size();
        int n = board[0].size();
        int count = 0;

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }

                int new_r = r + i;
                int new_c = c + j;

                if ((new_r >= 0 && new_r < m) && (new_c >= 0 && new_c < n))
                {
                    count += (board[new_r][new_c] % 2 == 1);
                }
            }
        }

        return count;
    }

    void print(vector<vector<int>> &board)
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
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}};
    solution.print(board);
    solution.gameOfLife(board);
    solution.print(board);

    return 0;
}

// https://leetcode.com/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150