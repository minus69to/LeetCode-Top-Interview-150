#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        while (left < right)
        {
            right = right & (right - 1);
        }

        return right;
    }
};

int main()
{
    Solution solution;
    cout << solution.rangeBitwiseAnd(10, 15);

    return 0;
}

// https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150