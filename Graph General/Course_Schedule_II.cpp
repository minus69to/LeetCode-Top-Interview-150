#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false);
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == false)
            {
                if (dfs(i, graph, visited, onPath, st) == true)
                {
                    return {};
                }
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }

    bool dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &onPath, stack<int> &st)
    {
        visited[node] = true;
        onPath[node] = true;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int neighbour = graph[node][i];
            if (visited[neighbour] == false)
            {
                if (dfs(neighbour, graph, visited, onPath, st) == true)
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
        st.push(node);

        return false;
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
};

int main()
{
    int numCourses = 10;
    vector<vector<int>> prerequisites = {
        {2, 0}, {3, 0}, {4, 0}, {3, 1}, {4, 1}, {5, 2}, {5, 3}, {6, 3}, {6, 4}, {7, 4}, {8, 5}, {8, 6}, {9, 6}, {9, 7}};

    Solution solution;
    vector<int> order = solution.findOrder(numCourses, prerequisites);

    for (int node : order)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

// https://leetcode.com/problems/course-schedule-ii/description/?envType=study-plan-v2&envId=top-interview-150