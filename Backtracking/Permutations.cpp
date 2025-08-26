#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        vector<vector<int>> answer;

        backtrack(nums, l, r, answer);

        return answer;
    }

    void backtrack(vector<int> &nums, int l, int r, vector<vector<int>> &answer)
    {
        if (l >= r)
        {
            answer.push_back(nums);
            return;
        }

        for (int i = l; i <= r; i++)
        {
            swap(nums[l], nums[i]);
            backtrack(nums, l + 1, r, answer);
            swap(nums[l], nums[i]);
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> answer = solution.permute(nums);

    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// https://leetcode.com/problems/permutations/description/?envType=study-plan-v2&envId=top-interview-150