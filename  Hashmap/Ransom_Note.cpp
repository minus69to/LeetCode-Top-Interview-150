#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> rmap;
        unordered_map<char, int> mmap;

        for (auto x : ransomNote)
        {
            rmap[x]++;
        }

        for (auto x : magazine)
        {
            mmap[x]++;
        }

        for (auto [k, v] : rmap)
        {
            if (rmap[k] > mmap[k])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    string ransomNote = "aa", magazine = "abb";
    Solution solution;
    cout << solution.canConstruct(ransomNote, magazine);

    return 0;
}

// https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150