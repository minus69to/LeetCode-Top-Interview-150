#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string sum = "";
        int carry = 0;

        int ia = a.size() - 1;
        int ib = b.size() - 1;

        while (ia >= 0 || ib >= 0 || carry == 1)
        {
            if (ia >= 0)
            {
                carry += (a[ia] - '0');
                ia--;
            }

            if (ib >= 0)
            {
                carry += (b[ib] - '0');
                ib--;
            }

            sum += (carry % 2 + '0');
            carry /= 2;
        }

        reverse(sum.begin(), sum.end());

        return sum;
    }
};

int main()
{
    Solution solution;
    string a = "1010", b = "1011";
    cout << solution.addBinary(a, b);

    return 0;
}

// https://leetcode.com/problems/add-binary/description/?envType=study-plan-v2&envId=top-interview-150