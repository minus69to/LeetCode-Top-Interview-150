#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> current;
        vector<vector<int>> answer;
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, current, answer);

        return answer;
    }

    void backtrack(vector<int> &candidates, int target, int start, vector<int> &current, vector<vector<int>> &answer)
    {
        if (target == 0)
        {
            answer.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (candidates[i] > target)
            {
                break;
            }

            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, answer);
            current.pop_back();
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {2, 3, 5};
    vector<vector<int>> answer = solution.combinationSum(nums, 8);

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

// https://leetcode.com/problems/combination-sum/description/?envType=study-plan-v2&envId=top-interview-150