#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            if (numbers[left] + numbers[right] < target)
            {
                left++;
            }
            else if (numbers[left] + numbers[right] > target)
            {
                right--;
            }
            else
            {
                left++;
                right++;
                break;
            }
        }

        return {left, right};
    }
};

int main()
{
    Solution solution;
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    vector<int> ans = solution.twoSum(numbers, target);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&envId=top-interview-150