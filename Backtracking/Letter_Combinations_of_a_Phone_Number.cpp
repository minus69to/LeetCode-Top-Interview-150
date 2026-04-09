#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<string> result;
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    void backtrack(string &digits, int index, string &current)
    {
        if(index == digits.size())
        {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        for(char ch : mapping[digit])
        {
            current.push_back(ch);
            backtrack(digits, index+1, current);
            current.pop_back();            
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return {};
        }
        
        string current = "";
        backtrack(digits, 0, current);
        return result;
    }
};

int main()
{
    string digits = "23";
    Solution solution;
    vector<string> result = solution.letterCombinations(digits);

    for(auto x : result)
    {
        cout << x << " ";
    }

    return 0;
}

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/?envType=study-plan-v2&envId=top-interview-150
