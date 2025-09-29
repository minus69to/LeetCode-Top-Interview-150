#include "00_BFS.cpp"

class Solution
{
public:
    int computeLeftHeight(TreeNode *node)
    {
        int height = 0;
        while (node != nullptr)
        {
            node = node->left;
            height++;
        }

        return height;
    }

    int computeRightHeight(TreeNode *node)
    {
        int height = 0;
        while (node != nullptr)
        {
            node = node->right;
            height++;
        }

        return height;
    }

    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left = computeLeftHeight(root);
        int right = computeRightHeight(root);

        if (left == right)
        {
            return (1 << left) - 1;
        }
        else
        {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};

int main()
{
    vector<int> nodes = {3, 20, 20, 1, 2, 2, 1};
    TreeNode *root = buildTree(nodes);
    printTree(root);

    Solution solution;
    cout << solution.countNodes(root);

    freeTree(root);

    return 0;
}

// https://leetcode.com/problems/count-complete-tree-nodes/description/?envType=study-plan-v2&envId=top-interview-150