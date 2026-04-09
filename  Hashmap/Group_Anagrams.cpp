#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<vector<int>, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++)
        {
            vector<int> cur(26, 0);

            for (int j = 0; j < strs[i].size(); j++)
            {
                cur[strs[i][j] - 'a']++;
            }

            mp[cur].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for (auto [k, v] : mp)
        {
            result.push_back(v);
        }

        return result;
    }
};

int main()
{
    vector<string> test1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solution;
    vector<vector<string>> result = solution.groupAnagrams(test1);

    for (auto group : result)
    {
        for (auto &word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

// https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150