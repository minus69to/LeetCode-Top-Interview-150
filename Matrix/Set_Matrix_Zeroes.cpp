#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int nRow = matrix.size(), nCol = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        for (int c = 0; c < nCol; c++)
        {
            if (matrix[0][c] == 0)
            {
                firstRowZero = true;
                break;
            }
        }

        for (int r = 0; r < nRow; r++)
        {
            if (matrix[r][0] == 0)
            {
                firstColZero = true;
                break;
            }
        }

        for (int r = 1; r < nRow; r++)
        {
            for (int c = 1; c < nCol; c++)
            {
                if (matrix[r][c] == 0)
                {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        for (int r = 1; r < nRow; r++)
        {
            for (int c = 1; c < nCol; c++)
            {
                if (matrix[r][0] == 0 || matrix[0][c] == 0)
                {
                    matrix[r][c] = 0;
                }
            }
        }

        if (firstRowZero)
        {
            for (int c = 0; c < nCol; c++)
            {
                matrix[0][c] = 0;
            }
        }

        if (firstColZero)
        {
            for (int r = 0; r < nRow; r++)
            {
                matrix[r][0] = 0;
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};
    solution.setZeroes(matrix);

    for (auto row : matrix)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

// https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150