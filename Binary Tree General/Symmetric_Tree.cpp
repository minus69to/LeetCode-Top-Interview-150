#include "00_BFS.cpp"

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
        {
            return true;
        }

        if (root1 == nullptr || root2 == nullptr)
        {
            return false;
        }

        if (root1->val != root2->val)
        {
            return false;
        }

        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
};

int main()
{
    vector<int> nodes = {3, 20, 20, 1, 2, 2, 1};
    TreeNode *root = buildTree(nodes);
    printTree(root);

    Solution solution;
    cout << solution.isSymmetric(root);

    freeTree(root);

    return 0;
}

// https://leetcode.com/problems/symmetric-tree/?envType=study-plan-v2&envId=top-interview-150