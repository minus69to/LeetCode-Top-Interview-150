#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int lastRow = triangle.size() - 1;
        vector<int> dp(triangle[lastRow].size(), INT_MIN);

        for (int i = 0; i < triangle[lastRow].size(); i++)
        {
            dp[i] = triangle[lastRow][i];
        }

        for (int r = lastRow - 1; r >= 0; r--)
        {
            for (int c = 0; c < triangle[r].size(); c++)
            {
                dp[c] = triangle[r][c] + min(dp[c], dp[c + 1]);
            }
        }

        return dp[0];
    }
};

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution solution;
    cout << solution.minimumTotal(triangle);

    return 0;
}

// https://leetcode.com/problems/triangle/description/?envType=study-plan-v2&envId=top-interview-150