#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int k = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[k++] = nums[i];
            }
        }

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;

        return k;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    cout << solution.removeElement(nums, 2);

    return 0;
}

// https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150