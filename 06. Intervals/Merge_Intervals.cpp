#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static bool compareEnd(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), compareEnd);
        vector<vector<int>> answer;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= end)
            {
                end = max(end, intervals[i][1]);
            }
            else
            {
                answer.push_back({start, end});

                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        answer.push_back({start, end});

        return answer;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> answer = solution.merge(intervals);

    for (int i = 0; i < answer.size(); i++)
    {

        cout << answer[i][0] << " " << answer[i][1] << endl;
    }

    return 0;
}

// https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-interview-150