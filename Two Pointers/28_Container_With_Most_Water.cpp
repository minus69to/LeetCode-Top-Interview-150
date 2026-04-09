#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int area = INT_MIN;

        while (left < right)
        {
            int tempArea = (right - left) * min(height[left], height[right]);
            area = max(area, tempArea);

            height[left] < height[right] ? left++ : right--;
        }

        return area;
    }
};

int main()
{
    Solution solution;
    vector<int> height = {8, 7, 2, 1};
    cout << solution.maxArea(height);

    return 0;
}

// https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150