#include "00_BFS.cpp"

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTreeUtil(root->left);
        invertTreeUtil(root->right);

        return root;
    }

    TreeNode *invertTreeUtil(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();

            TreeNode *temp = current->left;
            current->left = current->right;
            current->right = temp;

            if (current->left != nullptr)
            {
                q.push(current->left);
            }

            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }

        return root;
    }
};

int main()
{
    vector<int> nodes = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    TreeNode *root = buildTree(nodes);
    printTree(root);

    Solution solution;
    root = solution.invertTree(root);
    printTree(root);

    freeTree(root);

    return 0;
}

// https://leetcode.com/problems/invert-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150