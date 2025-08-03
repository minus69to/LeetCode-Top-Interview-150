#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int flag = 0;
        int count = 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (flag == 0 && s[i] == ' ')
            {
                continue;
            }
            else if (flag == 1 && s[i] == ' ')
            {
                break;
            }
            else
            {
                flag = 1;
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution solution;
    string s = "   fly me   to   the moon  ";
    cout << solution.lengthOfLastWord(s);

    return 0;
}

// https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150&roomId=rrcyTX