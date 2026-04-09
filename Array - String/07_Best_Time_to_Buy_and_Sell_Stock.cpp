#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = prices[0], profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] - buy > profit)
            {
                profit = prices[i] - buy;
            }
            if (prices[i] < buy)
            {
                buy = prices[i];
            }
        }

        return profit;
    }
};

int main()
{
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << solution.maxProfit(prices);

    return 0;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150