#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (auto coin : coins)
            {
                if (coin <= i && dp[i - coin] != amount + 1)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main()
{
    vector<int> coins = {3, 5, 7};
    Solution solution;
    cout << solution.coinChange(coins, 4);

    return 0;
}

// https://leetcode.com/problems/coin-change/description/?envType=study-plan-v2&envId=top-interview-150