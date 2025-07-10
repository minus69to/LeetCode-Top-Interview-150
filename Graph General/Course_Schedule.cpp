#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (dfs(i, graph, visited, onPath) == true)
            {
                return false;
            }
        }

        return true;
    }

    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        return graph;
    }

    bool dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &onPath)
    {
        // cout << node << " ";
        visited[node] = true;
        onPath[node] = true;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int neighbour = graph[node][i];
            if (visited[neighbour] == false)
            {
                if (dfs(neighbour, graph, visited, onPath) == true)
                {
                    return true;
                }
            }
            else if (onPath[neighbour] == true)
            {
                return true;
            }
        }

        onPath[node] = false;
        return false;
    }

    void printGraph(vector<vector<int>> graph)
    {
        for (int i = 0; i < graph.size(); i++)
        {
            cout << i << " :";
            for (int j = 0; j < graph[i].size(); j++)
            {
                cout << " " << graph[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Solution solution;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    vector<vector<int>> graph = solution.buildGraph(numCourses, prerequisites);
    solution.printGraph(graph);
    cout << solution.canFinish(numCourses, prerequisites);

    // vector<bool> visited(numCourses, false);
    // vector<bool> onPath(numCourses, false);
    // solution.dfs(0, graph, visited, onPath);
    // Now 0->1->2->3->4->5->6->0 forms a cycle

    return 0;
}

// https://leetcode.com/problems/course-schedule/?envType=study-plan-v2&envId=top-interview-150