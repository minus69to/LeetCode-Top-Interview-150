#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> smap;
        int maxlen = 0, left = 0;

        for (int forward = 0; forward < s.size(); forward++)
        {
            if (smap.find(s[forward]) == smap.end())
            {
                left = left; // character not seen before
            }
            else if (smap.find(s[forward]) != smap.end() && left > smap[s[forward]])
            {
                left = left; // character seen before, but **not in current window*
            }
            else if (smap.find(s[forward]) != smap.end() && left <= smap[s[forward]])
            {
                left = smap[s[forward]] + 1; // character repeated inside current window
            }

            smap[s[forward]] = forward;
            maxlen = max(maxlen, forward - left + 1);
        }

        return maxlen;
    }
};

int main()
{
    Solution solution;
    string s = "pwwkew";
    cout << solution.lengthOfLongestSubstring(s);

    return 0;
}

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150