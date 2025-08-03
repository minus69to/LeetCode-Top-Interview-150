#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        bool found = false;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                found = true;
                return mid;
            }
            else if (target < nums[mid])
            {
                right = mid - 1;
            }
            else if (target > nums[mid])
            {
                left = mid + 1;
            }
        }

        return (found == true || target < nums[mid]) ? mid : mid + 1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1,3,5,6};
    cout << solution.searchInsert(nums, 0) << endl;
    cout << solution.searchInsert(nums, 2) << endl;

    return 0;
}

// https://leetcode.com/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-interview-150