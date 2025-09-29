#include "00_BFS.cpp"

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<vector<int>> answer;
        bool leftToRight = true;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *current = q.front();
                q.pop();

                currentLevel.push_back(current->val);

                if (current->left != nullptr)
                {
                    q.push(current->left);
                }

                if (current->right != nullptr)
                {
                    q.push(current->right);
                }
            }

            if (!leftToRight)
            {
                reverse(currentLevel.begin(), currentLevel.end());
            }

            answer.push_back(currentLevel);
            leftToRight = !leftToRight;
        }

        return answer;
    }

    void print(vector<vector<int>> answer)
    {
        for (int i = 0; i < answer.size(); i++)
        {
            for (int j = 0; j < answer[i].size(); j++)
            {
                cout << answer[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    // vector<int> nodes = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    vector<int> nodes = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    TreeNode *root = buildTree(nodes);
    printTree(root);

    Solution solution;
    vector<vector<int>> answer = solution.zigzagLevelOrder(root);
    solution.print(answer);

    freeTree(root);

    return 0;
}

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150