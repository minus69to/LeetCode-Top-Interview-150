#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }

        // print(grid);

        return count;
    }

    void bfs(vector<vector<char>> &grid, int row, int col)
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = '0';

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

                if ((newRow >= 0 && newRow < grid.size()) && (newCol >= 0 && newCol < grid[0].size()) && (grid[newRow][newCol] == '1'))
                {
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = '0';
                }
            }
        }
    }

    void print(vector<vector<char>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    cout << solution.numIslands(grid);

    return 0;
}

// https://leetcode.com/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-interview-150