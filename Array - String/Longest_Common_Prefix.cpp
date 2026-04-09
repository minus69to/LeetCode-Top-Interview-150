#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        else if(strs.size() == 1)
        {
            return strs[0];
        }
        
        
        for (int c = 0; c < strs[0].size(); c++)
        {
            for (int r = 1; r < strs.size(); r++)
            {
                if (strs[r].size() <= c || strs[0][c] != strs[r][c])
                {
                    return strs[0].substr(0, c);
                }
            }
        }
        
        return "";
    }
};

int main()
{
    // vector<string> strs = {"flower","flow","flight"};
    vector<string> strs = {"d"};
    Solution solution;
    cout << solution.longestCommonPrefix(strs);

    return 0;
}

// https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150