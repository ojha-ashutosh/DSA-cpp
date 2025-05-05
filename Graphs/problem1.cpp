// you are given an undirected and disconnected graph G(V. E) having V vertices numbered from 0 to V-1 and E edges. Your tosk is to print its BFS traversal starting from the Oth vertex.
// BFS or Breadth-First Traversal of a graph is on algorithm used to visit all of the nodes of a given graph. in this traversal algorithm, one node is selected, and then all of the adjacent nodes are visited one by one.
// An undirected graph is a groph where all the edges are bidirectional, Le, they point from source to destination and destination to source.
// A graph is disconnected if ot least two vertices of the graph ore not

#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
using namespace std;
class Breadth_first_traversal
{
public:
    void prepareabjlist(unordered_map<int, list<int>> &abjlist, vector<pair<int, int>> edges)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;

            abjlist[u].push_back(v);
            abjlist[v].push_back(u);
        }
    }
    void bfs(unordered_map<int, list<int>> abjlist, unordered_map<int, bool> &visited, vector<int> &ans, int node)
    {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto i : abjlist[front])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
    vector<int> BFS(int vertex, vector<pair<int, int>> edges)
    {
        unordered_map<int, list<int>> abjlist;
        vector<int> ans;
        unordered_map<int, bool> visited;
        prepareabjlist(abjlist, edges);
        for (int i = 0; i < vertex; i++)
        {
            if (visited[i] == false)
                bfs(abjlist, visited, ans, i);
        }
        return ans;
    }

    // Given an undirected and disconnected graph G(V.),
    // containing 'V' vertices and 'E' edges,
    // the information about edges is given using 'GRAPH' matrix,
    // where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.
};
class depth_first_search
{
public:
    void prepareabjlist(unordered_map<int, list<int>> &abjlist, vector<pair<int, int>> edges)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;
            abjlist[u].push_back(v);
            abjlist[v].push_back(u);
        }
    }
    void dfs(unordered_map<int, list<int>> abjlist, unordered_map<int, bool> &visited, int node, vector<int> &temp)
    {
        temp.push_back(node);
        visited[node] = true;
        for (auto i : abjlist[node])
        {
            if (!visited[i])
            {
                dfs(abjlist, visited, i, temp);
            }
        }
    }
    vector<int> DFS(int vertex, vector<pair<int, int>> edges)
    {
        unordered_map<int, list<int>> abjlist;
        vector<int> ans;
        unordered_map<int, bool> visited;
        prepareabjlist(abjlist, edges);
        for (int i = 0; i < vertex; i++)
        {
            if (visited[i] == false)
            {
                dfs(abjlist, visited, i, ans);
            }
        }
        return ans;
    }
};
int main()
{
    Breadth_first_traversal bfsTraversal;

    // Define the number of vertices
    int vertices = 7;

    // Define edges of the graph
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {5, 6}};

    // Perform BFS traversal
    vector<int> bfsResult = bfsTraversal.BFS(vertices, edges);

    // Print the BFS result
    cout << "BFS Traversal: ";
    for (int vertex : bfsResult)
    {
        cout << vertex << " ";
    }
    cout << endl;

    depth_first_search dfsTraversal;
    vector<int> dfsResult = dfsTraversal.DFS(vertices, edges);
    // Print the DFS result
    cout << "DFS Traversal: ";
    for (int vertex : dfsResult)
    {
        cout << vertex << " ";
    }
    cout << endl;
    return 0;
}