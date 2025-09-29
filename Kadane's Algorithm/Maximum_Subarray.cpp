#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = INT_MIN;
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(currentSum, maxSum);
        }

        return maxSum;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << solution.maxSubArray(nums);

    return 0;
}

// https://leetcode.com/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-interview-150