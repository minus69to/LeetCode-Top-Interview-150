#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int minLen = INT_MAX;
        int currentSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            currentSum += nums[right];

            while (currentSum >= target)
            {
                minLen = min(minLen, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }

        return (minLen == INT_MAX ? 0 : minLen);
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 1, 1, 9, 1, 1, 1, 1};
    cout << solution.minSubArrayLen(11, nums);

    return 0;
}

// https://leetcode.com/problems/minimum-size-subarray-sum/?envType=study-plan-v2&envId=top-interview-150