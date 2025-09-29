#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        string current;
        vector<string> answer;

        backtrack(n, n, current, answer);

        return answer;
    }

    void backtrack(int openRemaining, int closeRemaining, string &current, vector<string> &answer)
    {
        if (openRemaining == 0 && closeRemaining == 0)
        {
            answer.push_back(current);
            return;
        }

        if (openRemaining > 0)
        {
            current.push_back('(');
            backtrack(openRemaining - 1, closeRemaining, current, answer);
            current.pop_back();
        }

        if (closeRemaining > openRemaining)
        {
            current.push_back(')');
            backtrack(openRemaining, closeRemaining - 1, current, answer);
            current.pop_back();
        }
    }
};

int main()
{
    Solution solution;
    vector<string> answer = solution.generateParenthesis(4);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}

// https://leetcode.com/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-interview-150