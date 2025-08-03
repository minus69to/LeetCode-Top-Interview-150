#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int i = 0;
        while (i < haystack.size())
        {
            if (haystack[i] == needle[0])
            {
                int k = 0;
                while (k < needle.size() && i + k < haystack.size())
                {
                    if (haystack[i + k] == needle[k] && k != needle.size() - 1)
                    {
                        k++;
                    }
                    else if (haystack[i + k] == needle[k] && k == needle.size() - 1)
                    {
                        return i;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            i++;
        }

        return -1;
    }
};

int main()
{
    Solution solution;
    string haystack = "sadbutsad", needle = "sad";
    // string haystack = "leetcode", needle = "leeto";
    cout << solution.strStr(haystack, needle);

    return 0;
}

// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150