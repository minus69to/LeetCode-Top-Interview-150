#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxReach = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (maxReach < i)
            {
                return false;
            }

            maxReach = max(maxReach, i + nums[i]);

            if (maxReach >= n - 1)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << solution.canJump(nums1) << endl; // Output: 1 (true)
    cout << solution.canJump(nums2) << endl; // Output: 0 (false)

    return 0;
}

// https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150