#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        string current = "";
        vector<string> words;
        for (auto ch : s)
        {
            if (ch == ' ')
            {
                words.push_back(current);
                current = "";
            }
            else
            {
                current += ch;
            }
        }
        words.push_back(current);

        unordered_map<char, string> p2w;
        unordered_map<string, char> w2p;

        if (pattern.size() != words.size())
        {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++)
        {
            char p = pattern[i];
            string w = words[i];

            if (p2w.find(p) != p2w.end() && p2w[p] != w)
            {
                return false;
            }

            if (w2p.find(w) != w2p.end() && w2p[w] != p)
            {
                return false;
            }

            p2w[p] = w;
            w2p[w] = p;
        }

        return true;
    }
};

int main()
{
    string pattern = "abba", s = "dog dog cat dog";
    Solution solution;
    cout << solution.wordPattern(pattern, s);

    return 0;
}

// https://leetcode.com/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150