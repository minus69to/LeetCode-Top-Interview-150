#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = getNext(n);

        while (fast != 1 && fast != slow)
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return fast == 1;
    }

    int getNext(int n)
    {
        int sum = 0;

        while (n)
        {
            int rem = n % 10;
            n = n / 10;
            sum += rem * rem;
        }

        return sum;
    }
};

int main()
{
    Solution solution;
    // int n = 19;
    int n = 2;
    cout << solution.isHappy(n);

    return 0;
}

// https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150