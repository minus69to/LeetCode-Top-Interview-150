#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = -prices[0], sell = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            // int temp = buy;
            buy = max(buy, sell-prices[i]);
            sell = max(sell, buy + prices[i]);
        }

        return sell;
    }
};

int main()
{
    Solution solution;
    vector<int> prices = {7,1,5,3,6,4};
    cout << solution.maxProfit(prices);

    return 0;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150