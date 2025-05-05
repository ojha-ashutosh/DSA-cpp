// bridges in a graph
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
class Bridge
{
public:
    void dfs(int node, int parant, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &abj, unordered_map<int, bool> &visited)
    {

        visited[node] = true;
        disc[node] = low[node] = timer++;

        for (auto neighbour : abj[node])
        {
            if (neighbour == parant)
                continue;
            if (!visited[neighbour])
            {
                dfs(neighbour, node, timer, disc, low, result, abj, visited);
                low[node] = min(low[node], low[neighbour]);
                // check edge id bridge
                if (disc[node] < low[neighbour])
                {
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(neighbour);
                    result.push_back(ans);
                }
            }
            else
            {
                // back edge
                low[node] = min(low[node], disc[neighbour]);
            }
        }
    }
    vector<vector<int>> findBridges(vector<vector<int>> edges, int v, int e)
    {
        unordered_map<int, list<int>> abj;
        for (int i = 0; i < e; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            abj[u].push_back(v);
            abj[v].push_back(u);
        }
        // disc[v]: Stores the discovery time of each node (initialized to -1).
        // low[v]: Tracks the lowest discovery time reachable from a node.
        // visited: Tracks whether a node has been visited.
        // timer: Keeps track of the time during DFS traversal.
        int timer = 0;
        vector<int> disc(v, -1);
        vector<int> low(v, -1);  
        int parant = -1;
        unordered_map<int, bool> visited;

        vector<vector<int>> result;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs(i, parant, timer, disc, low, result, abj, visited);
            }
        }
        return result;
    }
};
int main()
{
    int v = 6;
    int e = 7;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 4}, {4, 5}, {5, 3}};

    Bridge b;
    vector<vector<int>> bridges = b.findBridges(edges, v, e);

    cout << "Bridges in the graph are:\n";
    for (const auto &bridge : bridges)
    {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}
