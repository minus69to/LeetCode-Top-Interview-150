#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }

        int prev2 = 1; // from n = 3
        int prev1 = 2; // from n = 3
        int current = 0;

        for (int i = 3; i <= n; i++)
        {
            current = prev2 + prev1;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
};

int main()
{
    Solution solution;
    cout << solution.climbStairs(4);

    return 0;
}

// https://leetcode.com/problems/climbing-stairs/description/?envType=study-plan-v2&envId=top-interview-150