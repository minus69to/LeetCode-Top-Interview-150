#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static bool CompareEnd(const vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1];
    }

public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
        {
            return 0;
        }

        sort(points.begin(), points.end(), CompareEnd);
        int lastEnd = points[0][1];
        int count = 1;

        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > lastEnd)
            {
                count++;
                lastEnd = points[i][1];
            }
        }

        return count;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    // vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    // vector<vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << solution.findMinArrowShots(points);

    return 0;
}

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=top-interview-150