#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int size = s.size();
        vector<bool> dp(size + 1, false);
        dp[0] = true;

        for (int i = 1; i <= size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] == true && wordSet.find(s.substr(j, i - j)) != wordSet.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[size];
    }
};

int main()
{
    Solution solution;

    string s = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    vector<string> wordDict2 = {"leet", "put", "code"};
    vector<string> wordDict3 = {"leet"};
    vector<string> wordDict4 = {"code"};

    cout << solution.wordBreak(s, wordDict1) << endl;
    cout << solution.wordBreak(s, wordDict2) << endl;
    cout << solution.wordBreak(s, wordDict3) << endl;
    cout << solution.wordBreak(s, wordDict4) << endl;

    return 0;
}

// https://leetcode.com/problems/word-break/description/?envType=study-plan-v2&envId=top-interview-150