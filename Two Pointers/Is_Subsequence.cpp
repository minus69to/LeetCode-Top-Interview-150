#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int count = 0;

        for (int i = 0; i < t.size(); i++)
        {
            if (count == s.size())
            {
                return true;
            }

            if (s[count] == t[i])
            {
                count++;
            }
        }

        if (count == s.size())
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution solution;
    string s = "abc", t = "ahbgdc";
    // string s = "axc", t = "ahbgdc";
    cout << solution.isSubsequence(s, t);

    return 0;
}

// https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150