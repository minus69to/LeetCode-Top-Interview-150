#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() // Default constructor
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode)
    {
        val = x;
        left = leftNode;
        right = rightNode;
    }
};

TreeNode *buildTree(vector<int> nodes)
{
    if (nodes.empty() || nodes[0] == INT_MIN)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(nodes[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (i < nodes.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != INT_MIN)
        {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != INT_MIN)
        {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << "Empty TREE!" << endl;
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *current = q.front();
            q.pop();

            if (current != nullptr)
            {
                cout << current->val << " ";

                q.push(current->left);
                q.push(current->right);
            }
            else
            {
                cout << "null ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void freeTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);

    delete (root);
}

// int main()
// {
//     vector<int> nodes = {1, 2, 3, INT_MIN, 4, 5, INT_MIN, 6};
//     TreeNode *root = buildTree(nodes);
//     printTree(root);
//     freeTree(root);

//     return 0;
// }

// https://www.youtube.com/watch?v=EoAsWbO7sqg