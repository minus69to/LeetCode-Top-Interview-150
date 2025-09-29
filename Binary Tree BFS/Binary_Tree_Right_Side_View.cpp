#include "00_BFS.cpp"

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<int> result;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *current = q.front();
                q.pop();

                if (i == levelSize - 1)
                {
                    result.push_back(current->val);
                }

                if (current->left != nullptr)
                {
                    q.push(current->left);
                }

                if (current->right != nullptr)
                {
                    q.push(current->right);
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nodes = {1, 2, 3, INT_MIN, 4, 5, INT_MIN, 6};
    TreeNode *root = buildTree(nodes);
    printTree(root);

    Solution solution;
    vector<int> result = solution.rightSideView(root);
    for (auto x : result)
    {
        cout << x << " ";
    }

    freeTree(root);

    return 0;
}

// https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150