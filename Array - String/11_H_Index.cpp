#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end(), greater<int>());

        int h = 0;

        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] >= i+1)
            {
                h++;
            }
            else
            {
                break;
            }
        }

        return h;
    }
};

int main()
{
    Solution solution;
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << solution.hIndex(citations);

    return 0;
}

// https://leetcode.com/problems/h-index/?envType=study-plan-v2&envId=top-interview-150