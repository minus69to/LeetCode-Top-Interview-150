#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set numSet(nums.begin(), nums.end());
        int maxLen = 0;

        for (auto x : numSet)
        {
            if (numSet.find(x - 1) == numSet.end())
            {
                int curNum = x;
                int curLen = 1;

                while (numSet.find(curNum + 1) != numSet.end())
                {
                    curNum++;
                    curLen++;
                }

                maxLen = max(maxLen, curLen);
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 3, 2, 6, 9, 8, 7};
    cout << solution.longestConsecutive(nums);

    return 0;
}

// https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150