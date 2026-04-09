#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> result;

        if (nums1.empty() || nums2.empty() || k == 0)
        {
            return result;
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        for (int i = 0; i < min(k, (int)nums1.size()); i++)
        {
            minHeap.push({nums1[i] + nums2[0], i, 0});
        }

        while (!minHeap.empty() && result.size() < k)
        {
            vector<int> current = minHeap.top();
            minHeap.pop();

            int sum = current[0];
            int i = current[1];
            int j = current[2];

            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size())
            {
                minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums1 = {1, 7, 11}, nums2 = {2, 4, 6};
    int k = 3;

    Solution solution;
    vector<vector<int>> result = solution.kSmallestPairs(nums1, nums2, k);

    for (auto x : result)
    {
        cout << x[0] << " " << x[1] << endl;
    }

    return 0;
}

// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/?envType=study-plan-v2&envId=top-interview-150