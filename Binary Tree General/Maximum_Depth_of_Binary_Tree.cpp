#include "00_BFS.cpp"

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);
    }
};

int main()
{
    vector<int> nodes = {3, 20, 20, 1, 2, 2, 1};
    TreeNode *root = buildTree(nodes);
    printTree(root);

    Solution solution;
    cout << solution.maxDepth(root);

    freeTree(root);

    return 0;
}

// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150