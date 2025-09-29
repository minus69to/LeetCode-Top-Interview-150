#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (board[r][c] == word[0])
                {
                    if (dfs(board, word, r, c, 0) == true)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>> &board, string &word, int r, int c, int index)
    {
        if (index == word.size())
        {
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n)
        {
            return false;
        }

        if (board[r][c] != word[index])
        {
            return false;
        }

        vector<vector<int>> del = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        char temp = board[r][c];
        board[r][c] = '#';

        for (int k = 0; k < 4; k++)
        {
            int nr = r + del[k][0];
            int nc = c + del[k][1];

            if (dfs(board, word, nr, nc, index + 1) == true)
            {
                board[r][c] = temp; // If you want to use 'board' again here, you'd want it restored
                return true;
            }
        }

        board[r][c] = temp;

        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    cout << solution.exist(board, "CSE") << endl;
    cout << solution.exist(board, "CSE") << endl;

    return 0;
}

// https://leetcode.com/problems/word-search/description/?envType=study-plan-v2&envId=top-interview-150