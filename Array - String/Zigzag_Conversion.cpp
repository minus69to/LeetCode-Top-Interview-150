#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.size())
        {
            return s;
        }

        vector<string> straightVec(numRows, "");
        int curRow = 0;
        int direction = 1; // -1 for up, 1 for down

        for (auto x : s)
        {
            straightVec[curRow] += x;

            if (curRow == 0)
            {
                direction = 1;
            }
            else if (curRow == numRows - 1)
            {
                direction = -1;
            }

            curRow += direction;
        }

        string ans = "";

        for (auto x : straightVec)
        {
            ans += x;
        }

        return ans;
    }
};

int main()
{
    string s = "PAYPALISHIRING";
    Solution solution;
    cout << solution.convert(s, 4);

    return 0;
}

// https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150