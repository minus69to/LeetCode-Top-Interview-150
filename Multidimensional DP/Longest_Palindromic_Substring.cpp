#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
        {
            return "";
        }

        vector<vector<bool>> dp(n, vector<bool>(n));

        int ansStart = 0;
        int ansLen = 1;

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;

                ansStart = i;
                ansLen = 2;
            }
        }

        for (int length = 3; length <= n; length++)
        {
            for (int start = 0; start <= n - length; start++)
            {
                int end = start + length - 1;

                if (s[start] == s[end] && dp[start + 1][end - 1] == true)
                {
                    dp[start][end] = true;

                    if (length > ansLen)
                    {
                        ansLen = length;
                        ansStart = start;
                    }
                }
            }
        }

        return s.substr(ansStart, ansLen);
    }
};

int main()
{
    Solution solution;
    cout << solution.longestPalindrome("cabbac");

    return 0;
}

// https://leetcode.com/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=top-interview-150
