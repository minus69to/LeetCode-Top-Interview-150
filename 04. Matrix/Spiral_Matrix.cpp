#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        int up = 0, down = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (up <= down && left <= right)
        {
            for (int c = left; c <= right; c++)
            {
                result.push_back(matrix[up][c]);
            }
            up++;

            for (int r = up; r <= down; r++)
            {
                result.push_back(matrix[r][right]);
            }
            right--;

            if (up <= down)
            {
                for (int c = right; c >= left; c--)
                {
                    result.push_back(matrix[down][c]);
                }
                down--;
            }

            if (left <= right)
            {
                for (int r = down; r >= up; r--)
                {
                    result.push_back(matrix[r][left]);
                }
                left++;
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12}};

    // Output: [1,2,3,4,8,12,11,10,9,5,6,7]

    vector<int> result = solution.spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}

// https://leetcode.com/problems/spiral-matrix/?envType=study-plan-v2&envId=top-interview-150