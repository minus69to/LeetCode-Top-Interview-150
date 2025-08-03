#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int count = 0;
        for (int i = 0; i < candies.size(); i++)
        {
            count += candies[i];
        }

        return count;
    }
};

int main()
{
    Solution solution;
    vector<int> ratings = {1, 0, 2};
    cout << solution.candy(ratings);

    return 0;
}

// https://leetcode.com/problems/candy/description/?envType=study-plan-v2&envId=top-interview-150