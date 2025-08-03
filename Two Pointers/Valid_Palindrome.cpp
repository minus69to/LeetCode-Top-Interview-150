#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        vector<char> str;

        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 97 && s[i] <= 122)
            {
                str.push_back(s[i]);
            }
            else if (s[i] >= 48 && s[i] <= 57)
            {
                str.push_back(s[i]);
            }
            else if (s[i] >= 65 && s[i] <= 90)
            {
                str.push_back(s[i] + 32);
            }
        }

        int left = 0;
        int right = str.size() - 1;

        while (left < right)
        {
            if(str[left] != str[right])
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }

        // for(auto x : str)
        // {
        //     cout << x;
        // }
        // cout << endl;

        return true;
    }
};

int main()
{
    Solution solution;
    string s = " ";
    cout << solution.isPalindrome(s);

    return 0;
}

// https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150