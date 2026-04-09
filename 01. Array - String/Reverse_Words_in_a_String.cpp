#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> temp;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else
            {
                string curStr = "";

                while (i < s.size() && s[i] != ' ')
                {
                    curStr += s[i];
                    i++;
                }
                
                temp.push_back(curStr);
            }
        }

        string ans = "";

        for (int i = temp.size()-1; i >= 0; i--)
        {
            ans += temp[i];

            if (i != 0)
            {
                ans += ' ';
            }
        }
        
        return ans;
    }
};

int main()
{
    string s = "    a good   example   ";
    Solution solution;
    cout << solution.reverseWords(s);

    return 0;
}

// https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=top-interview-150