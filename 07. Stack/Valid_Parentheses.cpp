#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stk.push(s[i]);
            }
            else
            {
                if (stk.size() > 0 && s[i] == ')' && stk.top() == '(')
                {
                    stk.pop();
                }
                else if (stk.size() > 0 && s[i] == '}' && stk.top() == '{')
                {
                    stk.pop();
                }
                else if (stk.size() > 0 && s[i] == ']' && stk.top() == '[')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return stk.size() == 0;
    }
};

int main()
{
    Solution solution;
    string s1 = "()[]{}", s2 = "(]";
    cout << solution.isValid(s1) << endl;
    cout << solution.isValid(s2) << endl;

    return 0;
}

// https://leetcode.com/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-interview-150