#include "00_BFS.cpp"

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }

        if (p == nullptr || q == nullptr)
        {
            return false;
        }

        queue<TreeNode *> pq;
        pq.push(p);

        queue<TreeNode *> qq;
        qq.push(q);

        while (!pq.empty() && !qq.empty())
        {
            TreeNode *currentp = pq.front();
            pq.pop();

            TreeNode *currentq = qq.front();
            qq.pop();

            if (currentp == nullptr && currentq == nullptr)
            {
                continue;
            }

            if (currentp == nullptr || currentq == nullptr || currentp->val != currentq->val)
            {
                return false;
            }

            pq.push(currentp->left);
            pq.push(currentp->right);
            qq.push(currentq->left);
            qq.push(currentq->right);
        }

        return pq.empty() && qq.empty();
    }
};

int main()
{
    vector<int> nodes1 = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    TreeNode *root1 = buildTree(nodes1);
    printTree(root1);

    vector<int> nodes2 = {3, 9, 20, INT_MIN, INT_MIN, 7, 15};
    TreeNode *root2 = buildTree(nodes2);
    printTree(root2);

    Solution solution;
    cout << solution.isSameTree(root1, root2);

    freeTree(root1);
    freeTree(root2);

    return 0;
}

// https://leetcode.com/problems/same-tree/description/?envType=study-plan-v2&envId=top-interview-150