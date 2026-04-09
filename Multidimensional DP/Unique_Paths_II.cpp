#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
        {
            return 0;
        }

        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[j] = 0;
                }
                else
                {
                    if (j > 0)
                    {
                        dp[j] = dp[j] + dp[j - 1];
                    }
                }
                cout << dp[j] << " ";
            }
            cout << endl;
        }

        return dp[n - 1];
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 0}, {1, 1}, {0, 0}};
    Solution solution;
    cout << solution.uniquePathsWithObstacles(grid);

    return 0;
}

// https://leetcode.com/problems/unique-paths-ii/description/?envType=study-plan-v2&envId=top-interview-150