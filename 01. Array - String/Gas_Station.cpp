#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int currentFuel = 0;
        int totalFuel = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            int diff = gas[i] - cost[i];

            totalFuel += diff;
            currentFuel += diff;

            if (currentFuel < 0)
            {
                start = i + 1;
                currentFuel = 0;
            }
        }

        if (totalFuel >= 0)
        {
            return start;
        }

        return -1;
    }
};

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5}, cost = {3, 4, 5, 1, 2};
    Solution solution;
    cout << solution.canCompleteCircuit(gas, cost);

    return 0;
}

// https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150