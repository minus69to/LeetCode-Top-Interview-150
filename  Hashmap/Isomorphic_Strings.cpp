#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;

        for (int i = 0; i < s.size(); i++)
        {
            if (smap.find(s[i]) != smap.end() && smap[s[i]] != t[i])
            {
                return false;
            }

            if (tmap.find(t[i]) != tmap.end() && tmap[t[i]] != s[i])
            {
                return false;
            }

            smap[s[i]] = t[i];
            tmap[t[i]] = s[i];
        }

        return true;
    }
};

int main()
{
    string s = "egg", t = "abd";
    Solution solution;
    cout << solution.isIsomorphic(s, t);

    return 0;
}

// https://leetcode.com/problems/isomorphic-strings/?envType=study-plan-v2&envId=top-interview-150