#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return 0;
        }

        int jumps = 0;
        int curReach = 0;
        int maxReach = 0;

        for (int i = 0; i <= nums.size() - 2; i++)
        {
            maxReach = max(maxReach, i + nums[i]);

            if (i == curReach)
            {
                jumps++;
                curReach = maxReach;

                if (curReach >= nums.size() - 1) // Optimization(Optional)
                {
                    break;
                }
            }
        }

        return jumps;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 4, 3, 1, 1, 1, 1};
    cout << solution.jump(nums1) << endl; // Output: 2
    cout << solution.jump(nums2) << endl; // Output: 3

    return 0;
}

// https://leetcode.com/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150https://leetcode.com/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150