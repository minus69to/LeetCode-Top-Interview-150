#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;
        unsigned int num = n;

        while (num != 0)
        {
            count++;
            num = num & (num - 1);
        }

        return count;
    }
};

int main()
{
    Solution solution;
    cout << solution.hammingWeight(255);

    return 0;
}

// https://leetcode.com/problems/number-of-1-bits/description/?envType=study-plan-v2&envId=top-interview-150