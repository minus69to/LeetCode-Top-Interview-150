#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i1 = m - 1, i2 = n - 1, il = m + n - 1;

        while (i1 >= 0 && i2 >= 0)
        {
            if (nums1[i1] > nums2[i2])
            {
                nums1[il--] = nums1[i1--];
            }
            else
            {
                nums1[il--] = nums2[i2--];
            }
        }

        while (i2 >= 0)
        {
            nums1[il--] = nums2[i2--];
        }

        for (int i = 0; i < m + n; i++)
        {
            cout << nums1[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution solution;
    int m = 3, n = 3;
    vector<int> nums1 = {3, 7, 8, 0, 0, 0}, nums2 = {2, 5, 6};
    solution.merge(nums1, m, nums2, n);

    return 0;
}

// https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150