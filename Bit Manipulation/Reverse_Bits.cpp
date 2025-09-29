#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverseBits(int n)
    {
        unsigned int num = (unsigned int)n;
        unsigned int ans = 0;

        for (int i = 0; i < 32; i++)
        {
            ans <<= 1;
            ans |= (num & 1);
            num >>= 1;
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.reverseBits(2147483644);

    return 0;
}

// https://leetcode.com/problems/reverse-bits/description/?envType=study-plan-v2&envId=top-interview-150