#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        int i_2 = nums[0];
        int i_1 = max(nums[0], nums[1]);
        int i = 0;

        for (int k = 2; k < nums.size(); k++)
        {
            i = max(i_2 + nums[k], i_1);
            i_2 = i_1;
            i_1 = i;
        }

        return i;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << solution.rob(nums);

    return 0;
}

// https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=top-interview-150