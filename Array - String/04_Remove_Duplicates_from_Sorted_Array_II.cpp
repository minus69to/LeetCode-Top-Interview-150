#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
        {
            return nums.size();
        }
        
        int k = 1;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] != nums[k - 1])
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
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    cout << solution.removeDuplicates(nums);

    return 0;
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=study-plan-v2&envId=top-interview-150