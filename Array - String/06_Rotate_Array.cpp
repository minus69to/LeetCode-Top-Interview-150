#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int left = 0, right = nums.size() - 1;
        k %= nums.size();  // normalize k

        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end() - k);

        while (left <= right)
        {
            swap(nums[left++], nums[right--]);
        }

        print(nums);
    }

    void print(vector<int> &nums)
    {
        for (int x : nums)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    solution.rotate(nums, 23);

    return 0;
}

// https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150