#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int answer = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            answer ^= nums[i];
        }

        return answer;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << solution.singleNumber(nums);

    return 0;
}

// https://leetcode.com/problems/single-number/description/?envType=study-plan-v2&envId=top-interview-150