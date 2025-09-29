#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int nRow = matrix.size();
        int nCol = matrix[0].size();

        for (int i = 0; i < nRow; i++)
        {
            if (target >= matrix[i][0] && target <= matrix[i][nCol - 1])
            {
                int mid = 0;
                int left = 0;
                int right = nCol-1;

                while (left < right)
                {
                    mid = left + (right - left) / 2;

                    if (target == matrix[i][mid])
                    {
                        return true;
                    }
                    else if (target < matrix[i][mid])
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }

                return false;
            }
            else
            {
                continue;
            }
        }

        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << solution.searchMatrix(matrix, 13);

    return 0;
}

// https://leetcode.com/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-interview-150