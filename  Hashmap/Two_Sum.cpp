#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (umap.find(complement) != umap.end())
            {
                return {i, umap[complement]};
            }

            umap[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 2, 1, 4};
    int target = 6;
    vector<int> answer = solution.twoSum(nums, target);
    cout << answer[0] << " " << answer[1] << endl;

    return 0;
}

// https://leetcode.com/problems/two-sum/description/?envType=study-plan-v2&envId=top-interview-150