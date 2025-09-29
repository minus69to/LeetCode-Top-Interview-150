#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        int reversedHalf = 0;

        while (x > reversedHalf)
        {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        return (x == reversedHalf) || (x == reversedHalf / 10);
    }
};

int main()
{
    Solution solution;
    cout << solution.isPalindrome(14321) << endl;
    cout << solution.isPalindrome(124321) << endl;

    return 0;
}

// https://leetcode.com/problems/palindrome-number/description/?envType=study-plan-v2&envId=top-interview-150