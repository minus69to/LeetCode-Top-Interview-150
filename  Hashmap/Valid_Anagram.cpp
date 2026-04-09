#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;

        for (int i = 0; i < s.size(); i++)
        {
            smap[s[i]]++;
            tmap[t[i]]++;
        }

        return smap == tmap;
    }
};

int main()
{
    string s = "anagram", t = "nagaram";
    Solution solution;
    cout << solution.isAnagram(s, t);

    return 0;
}

// https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150