#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode)
    {
        val = x;
        left = leftNode;
        right = rightNode;
    }
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildBST(nums, 0, nums.size() - 1);
    }

    TreeNode *buildBST(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int mid = left + (right - left) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }
};

void inorderPrint(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main()
{
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *root = solution.sortedArrayToBST(nums);

    inorderPrint(root);

    return 0;
}

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/?envType=study-plan-v2&envId=top-interview-150