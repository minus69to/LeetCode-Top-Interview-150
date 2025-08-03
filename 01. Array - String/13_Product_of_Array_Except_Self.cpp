#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> answer(nums.size(), 1);

        int prefix = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            answer[i] = answer[i] * suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> answer = solution.productExceptSelf(nums);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}