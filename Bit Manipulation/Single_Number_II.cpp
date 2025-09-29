#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0, twos = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }

        return ones;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 1, 2, 1, 2, 3};
    cout << solution.singleNumber(nums);

    return 0;
}