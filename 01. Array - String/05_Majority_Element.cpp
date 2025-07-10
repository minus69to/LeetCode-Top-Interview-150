#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0, ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                count++;
                ans = nums[i];
            }
            else if (nums[i] == ans) // count > 0 && nums[i] == ans
            {
                count++;
            }
            else // count > 0 && nums[i] != ans
            {
                count--;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 1, 3, 1, 3, 1};
    cout << solution.majorityElement(nums);

    return 0;
}

// https://leetcode.com/problems/majority-element/?envType=study-plan-v2&envId=top-interview-150