#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1); // If we reach here, all digits were 9 → need an extra 1 at the front

        return digits;
    }
};

int main()
{
    Solution solution;
    vector<int> digits1 = {1, 2, 3};
    vector<int> digits2 = {9, 9, 9};
    // vector<int> answer = solution.plusOne(digits1);
    vector<int> answer = solution.plusOne(digits2);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}

// https://leetcode.com/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150