#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> r2c = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int total = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i < s.size() - 1 && r2c[s[i]] < r2c[s[i + 1]])
            {
                total -= r2c[s[i]];
            }
            else
            {
                total += r2c[s[i]];
            }
        }

        return total;
    }
};

int main()
{
    string s = "MCMXCIV";
    Solution solution;
    cout << solution.romanToInt(s);

    return 0;
}

// https://leetcode.com/problems/roman-to-integer/?envType=study-plan-v2&envId=top-interview-150