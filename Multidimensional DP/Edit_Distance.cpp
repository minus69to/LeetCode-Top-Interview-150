#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }

        for (int j = 0; j <= n; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                }
            }
        }

        // for (int i = 0; i <= m; i++)
        // {
        //     for (int j = 0; j <= n; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        return dp[m][n];
    }
};

int main()
{
    Solution solution;
    string word1 = "horse", word2 = "ros";
    cout << solution.minDistance(word1, word2);

    return 0;
}

// https://leetcode.com/problems/edit-distance/description/?envType=study-plan-v2&envId=top-interview-150