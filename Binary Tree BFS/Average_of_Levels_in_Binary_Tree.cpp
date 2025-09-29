#include "00_BFS.cpp"

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<double> answer;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();
            double sum = 0;

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *current = q.front();
                q.pop();

                sum += current->val;

                if (current->left != nullptr)
                {
                    q.push(current->left);
                }

                if (current->right != nullptr)
                {
                    q.push(current->right);
                }
            }

            answer.push_back(sum / levelSize);
        }

        return answer;
    }

    void print(vector<double> answer)
    {
        for (auto x : answer)
        {
            cout << x << " ";
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
    vector<double> answer = solution.averageOfLevels(root);
    solution.print(answer);

    freeTree(root);

    return 0;
}

// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150