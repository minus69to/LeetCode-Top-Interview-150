#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[k] != nums[i])
            {
                nums[++k] = nums[i];
            }
        }

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;

        return ++k;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << solution.removeDuplicates(nums);

    return 0;
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150