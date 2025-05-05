// articulation point
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <unordered_set>
using namespace std;
class articulationpnt
{
public:
    void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, unordered_set<int> &res, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &abj)
    {
        visited[node] = true;
        disc[node] = low[node] = timer++;
        int child = 0;
        for (auto neighbour : abj[node])
        {
            if (neighbour == parent)
            {
                continue;
            }
            if (!visited[neighbour])
            {
                dfs(neighbour, node, timer, disc, low, res, visited, abj);
                low[node] = min(low[node], low[neighbour]);
                // sloving source case (parent -1 ) alag se
                if (disc[node] <= low[neighbour] && parent != -1)
                {
                    res.insert(node);
                }
            }
            else
            {
                // back edge
                low[node] = min(low[node], disc[neighbour]);
            }
            child++;
        }
        if (parent != -1 && child > 1)
        {
            res.insert(node);
        }
    }
    unordered_set<int> findArticulationpnt(vector<vector<int>> edges, int v, int e)
    {
        unordered_map<int, list<int>> abj;
        for (int i = 0; i < e; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            abj[u].push_back(v);
            abj[v].push_back(u);
        }

        int timer = 0;
        int parent = -1;
        vector<int> disc(v, -1);
        vector<int> low(v, -1);
        unordered_map<int, bool> visited;

        unordered_set<int> res;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs(i, parent, timer, disc, low, res, visited, abj);
            }
        }
        return res;
    }
};
int main()
{
    int v = 7; // number of vertices
    int e = 7; // number of edges

    // Define the edges of the graph
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 4}, {4, 5}, {5, 6}};

    articulationpnt ap;
    unordered_set<int> articulationPoints = ap.findArticulationpnt(edges, v, e);

    cout << "Articulation Points in the graph are: \n";
    for (int i : articulationPoints)
    {
        cout << i << " ";
    }

    return 0;
}
