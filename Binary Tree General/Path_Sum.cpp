#include "00_BFS.cpp"

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }

        return dfs(root, targetSum);
    }

    bool dfs(TreeNode *root, int remaining)
    {
        if (root == nullptr)
        {
            return false;
        }

        remaining -= root->val;

        if (root->left == nullptr && root->right == nullptr)
        {
            return remaining == 0;
        }

        bool left = dfs(root->left, remaining);
        bool right = dfs(root->right, remaining);

        return left || right;
    }
};

int main()
{
    vector<int> nodes = {3, 20, 20, 1, 2, 2, 1};
    TreeNode *root = buildTree(nodes);
    printTree(root);

    Solution solution;
    cout << solution.hasPathSum(root, 5);

    freeTree(root);

    return 0;
}

// https: // leetcode.com/problems/path-sum/description/?envType=study-plan-v2&envId=top-interview-150