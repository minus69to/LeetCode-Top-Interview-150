#include "00_BFS.cpp"
using namespace std;

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr)
        {
            return root;
        }

        return left != nullptr ? left : right;
    }
};

int main()
{
    vector<int> nodes = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    TreeNode *root = buildTree(nodes);
    printTree(root);

    Solution solution;
    root = solution.lowestCommonAncestor(root, root->left, root->right);
    cout << root->val;
    // printTree(root);

    freeTree(root);

    return 0;
}

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/?envType=study-plan-v2&envId=top-interview-150