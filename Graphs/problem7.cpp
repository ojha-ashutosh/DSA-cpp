// DIJKSTRA`S SHORTEST PATH
// dont work on negative weight
#include <iostream>
#include <unordered_map>
#include <set>
#include <limits.h>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;
class dijkstra
{
public:
    vector<int> dijkstraalgo(vector<vector<int>> &data, int edges, int vertex, int source)
    {
        unordered_map<int, list<pair<int, int>>> abj;
        for (int i = 0; i < edges; i++)
        {
            int u = data[i][0];
            int v = data[i][1];
            int w = data[i][2];

            abj[u].push_back(make_pair(v, w));
            abj[v].push_back(make_pair(u, w));
        }

        vector<int> dist(6, INT_MAX);
        set<pair<int, int>> s; // distance,node
        dist[source] = 0;
        s.insert(make_pair(0, source));
        while (!s.empty())
        {
            // it is a set  if we fatch the top it will get us a entry with minimum distance
            auto top = *(s.begin());
            int distancenode = top.first;
            int node = top.second;
            // remove top record
            s.erase(s.begin());
            for (auto neighbour : abj[node])
            {
                if (distancenode + neighbour.second < dist[neighbour.first])
                {

                    auto record = s.find(make_pair(dist[neighbour.first], neighbour.first));
                    if (record != s.end())
                    {
                        s.erase(record);
                    }
                    dist[neighbour.first] = distancenode + neighbour.second;
                    s.insert(make_pair(dist[neighbour.first], neighbour.first));
                }
            }
        }
        return dist;
    }
};

int main()
{
    vector<vector<int>> data = {
        {0, 1, 4}, {0, 2, 1}, {2, 1, 2}, {1, 3, 1}, {2, 3, 5}};
    int edges = 5;
    int vertices = 5;
    int source = 0;

    dijkstra d;
    vector<int> result = d.dijkstraalgo(data, edges, vertices, source);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}