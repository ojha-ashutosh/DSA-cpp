// cycle detection in directed graph
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
using namespace std;
class solbydfs
{
public:
    void createabj(unordered_map<int, list<int>> &abj, vector<vector<int>> edges, int n)
    {
        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            abj[u].push_back(v);
        }
    }
    bool prob(unordered_map<int, list<int>> abj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, int node)
    {
        visited[node] = 1;
        dfsvisited[node] = 1;
        for (int neighbour : abj[node])
        {
            if (!visited[neighbour])
            {
                return prob(abj, visited, dfsvisited, neighbour);
            }
            else if (dfsvisited[neighbour])
            {
                // condition visited[neighbour]==true && dfsvisited[neighbour]==true --->cycle
                return true;
            }
        }
        dfsvisited[node] = false;
        return false;
    }
    bool iscyclic(vector<vector<int>> edges, int n)
    {
        unordered_map<int, list<int>> abj;
        createabj(abj, edges, n);
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsvisited;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bool check = prob(abj, visited, dfsvisited, i);
                if (check == true)
                    return true;
            }
        }
        return false;
    }
};
class solbybfs
{
public:
    // by kahn's algo problem 4

    void createabj(unordered_map<int, list<int>> &abj, vector<pair<int, int>> edges)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;

            abj[u].push_back(v);
        }
    }
    bool soln(vector<pair<int, int>> edges, int v)
    {
        unordered_map<int, list<int>> abj;
        createabj(abj, edges);

        vector<int> indegree(v, 0);
        for (int i = 0; i < v; i++)
        {
            for (int j : abj[i])
            {
                indegree[j]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            count++;
            for (int neighbour : abj[front])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        if (count == v)
            return false; // valid topological sort (that is it is a directed acylic graph)
        else
            return true;
    }
};
int main()
{
    solbydfs solution;

    // Number of edges
    int n = 4;

    // Directed graph edges
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 1} // Cycle exists here
    };

    // Check if the graph contains a cycle
    if (solution.iscyclic(edges, n))
    {
        cout << "Cycle detected!" << endl;
    }
    else
    {
        cout << "No cycle detected!" << endl;
    }
    

    solbybfs solutionBFS;

    // Number of vertices
    int v = 4;

    // Directed graph edges
    vector<pair<int, int>> edgess = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 1} // Cycle exists here
    };

    // Check if the graph contains a cycle
    if (solutionBFS.soln(edgess, v)) {
        cout << "Cycle detected using BFS!" << endl;
    } else {
        cout << "No cycle detected using BFS!" << endl;
    }

    return 0;
}