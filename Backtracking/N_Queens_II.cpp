#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        unordered_set<int> cols;
        unordered_set<int> diagPlus;
        unordered_set<int> diagMinus;
        int count = 0;

        backtrack(0, cols, diagPlus, diagMinus, count, n);

        return count;
    }

    void backtrack(int row, unordered_set<int> &cols, unordered_set<int> &diagPlus, unordered_set<int> &diagMinus, int &count, int n)
    {
        if (row == n)
        {
            count++;
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (canPlace(row, col, cols, diagPlus, diagMinus))
            {
                cols.insert(col);
                diagPlus.insert(row + col);
                diagMinus.insert(row - col);

                backtrack(row + 1, cols, diagPlus, diagMinus, count, n);

                cols.erase(col);
                diagPlus.erase(row + col);
                diagMinus.erase(row - col);
            }
        }
    }

    bool canPlace(int row, int col, unordered_set<int> &cols, unordered_set<int> &diagPlus, unordered_set<int> &diagMinus)
    {
        if (cols.find(col) == cols.end() && diagPlus.find(row + col) == diagPlus.end() && diagMinus.find(row - col) == diagMinus.end())
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution solution;
    cout << solution.totalNQueens(3);

    return 0;
}

// https://leetcode.com/problems/n-queens-ii/description/?envType=study-plan-v2&envId=top-interview-150