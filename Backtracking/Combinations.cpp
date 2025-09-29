#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> current;
        vector<vector<int>> answer;

        dfs(n, k, 1, current, answer);

        return answer;
    }

    void dfs(int n, int k, int start, vector<int> &current, vector<vector<int>> &answer)
    {
        if (current.size() == k)
        {
            answer.push_back(current);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            current.push_back(i);
            dfs(n, k, i + 1, current, answer);
            current.pop_back();
        }
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> answer = solution.combine(4, 2);

    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// https://leetcode.com/problems/combinations/description/?envType=study-plan-v2&envId=top-interview-150