#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;

        for (auto x : tokens)
        {
            if (x == "+" || x == "-" || x == "*" || x == "/")
            {
                int a = stk.top();
                stk.pop();

                int b = stk.top();
                stk.pop();

                int res = operate(b, a, x);
                stk.push(res);
            }
            else
            {
                stk.push(stoi(x));
            }
        }

        return stk.top();
    }

    int operate(int b, int a, string op)
    {
        if (op == "+")
        {
            return b + a;
        }
        else if (op == "-")
        {
            return b - a;
        }
        else if (op == "*")
        {
            return b * a;
        }
        else
        {
            return b / a;
        }

        return 0;
    }
};

int main()
{
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution solution;
    cout << solution.evalRPN(tokens);

    return 0;
}

// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=study-plan-v2&envId=top-interview-150