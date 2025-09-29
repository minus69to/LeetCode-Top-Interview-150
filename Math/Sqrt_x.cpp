#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 1;
        int right = x;
        int result = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (mid <= x / mid) // Use division to avoid overflow: mid <= x/mid instead of mid*mid <= x
            {
                result = mid; // mid could be the answer, but search for larger
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    cout << solution.mySqrt(8);

    return 0;
}

// https://leetcode.com/problems/sqrtx/description/?envType=study-plan-v2&envId=top-interview-150