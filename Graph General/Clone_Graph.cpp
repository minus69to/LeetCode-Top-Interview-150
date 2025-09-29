#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        queue<Node *> q;
        q.push(node);

        unordered_map<Node *, Node *> visited;
        visited[node] = new Node(node->val);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            for (int i = 0; i < current->neighbors.size(); i++)
            {
                Node *neighbor = current->neighbors[i];

                if (visited.find(neighbor) == visited.end())
                {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                visited[current]->neighbors.push_back(visited[neighbor]);
            }
        }

        return visited[node];
    }
};

void printGraph(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    queue<Node *> q;
    q.push(node);

    unordered_set<Node *> visited;

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->val << " :";

        for (int i = 0; i < current->neighbors.size(); i++)
        {
            Node *neighbor = current->neighbors[i];
            cout << " " << neighbor->val;

            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    printGraph(n1);

    Solution solution;
    Node *cloned = solution.cloneGraph(n1);
    printGraph(cloned);

    return 0;
}

// https://leetcode.com/problems/clone-graph/description/?envType=study-plan-v2&envId=top-interview-150