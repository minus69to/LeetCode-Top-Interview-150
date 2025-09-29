#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int maxSum = INT_MIN, currentMax = 0;
        int minSum = INT_MAX, currentMin = 0;
        int totalSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];

            currentMax = max(nums[i], currentMax + nums[i]);
            maxSum = max(currentMax, maxSum);

            currentMin = min(nums[i], currentMin + nums[i]);
            minSum = min(currentMin, minSum);
        }

        // If all numbers are negative, maxSum is the answer
        if (maxSum < 0)
        {
            return maxSum;
        }

        int circularMax = totalSum - minSum;

        return max(maxSum, circularMax);
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {5, -3, 5};
    cout << solution.maxSubarraySumCircular(nums);

    return 0;
}

// https://leetcode.com/problems/maximum-sum-circular-subarray/description/?envType=study-plan-v2&envId=top-interview-150