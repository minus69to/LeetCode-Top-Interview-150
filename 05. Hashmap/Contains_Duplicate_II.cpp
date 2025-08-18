#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++)
        {
            if (umap.find(nums[i]) != umap.end() && i - umap[nums[i]] <= k)
            {
                return true;
            }
            
            umap[nums[i]] = i;
        }
        
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {1,2,3,1};
    vector<int> nums2 = {1,2,3,1,2,3};
    cout << solution.containsNearbyDuplicate(nums1, 3) << endl;
    cout << solution.containsNearbyDuplicate(nums2, 2) << endl;

    return 0;
}

// https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150