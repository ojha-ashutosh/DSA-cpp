// prim's algo
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <limits.h>
using namespace std;
class minimumSpanningTree
{
public:
    vector<pair<pair<int, int>, int>> MST(vector<pair<pair<int, int>, int>> data, int source, int n)
    {
        unordered_map<int, list<pair<int, int>>> abj;
        for (int i = 0; i < data.size(); i++)
        {
            int u = data[i].first.first;
            int v = data[i].first.second;
            int w = data[i].second;

            abj[u].push_back(make_pair(v, w));
            abj[v].push_back(make_pair(u, w));
        }
        // in key we will store minimum weight
        vector<int> key(n, INT_MAX); // node staring with 0 if with 1 then size =n+1
        vector<int> parants(n, -1);
        vector<bool> isMST(n, false);

        key[source] = 0;
        parants[source] = -1;
        for (int i = 0; i < n; i++)
        {
            int mini = INT_MAX;
            int u;
            for (int v = 0; v < n; v++)
            {
                if (isMST[v] == false && key[v] < mini)
                {
                    u = v;
                    mini = key[v];
                }
            }

            isMST[u] = true;

            for (auto neighbour : abj[u])
            {
                int v = neighbour.first;
                int w = neighbour.second;
                if (isMST[v] == false && key[v] > w)
                {
                    key[v] = w;
                    parants[v] = u;
                }
            }
        }
        vector<pair<pair<int, int>, int>> res;
        // parant of 0 is -1;
        for (int i = 1; i < n; i++)
        {
            res.push_back(make_pair(make_pair(parants[i], i), key[i]));
        }
        return res;
    }
};
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    minimumSpanningTree mst;
    vector<pair<pair<int, int>, int>> edges = {
        {{0, 1}, 4}, {{0, 7}, 8}, {{1, 2}, 8}, {{1, 7}, 11}, {{2, 3}, 7}, {{2, 8}, 2}, {{2, 5}, 4}, {{3, 4}, 9}, {{3, 5}, 14}, {{4, 5}, 10}, {{5, 6}, 2}, {{6, 7}, 1}, {{6, 8}, 6}, {{7, 8}, 7}};
    int source = 0; // Starting node
    int n = 9;      // Number of nodes (0 to 8)

    vector<pair<pair<int, int>, int>> result = mst.MST(edges, source, n);

    cout << "Edges in the MST:" << endl;
    for (auto edge : result)
    {
        cout << edge.first.first << " - " << edge.first.second << " with weight " << edge.second << endl;
    }

    return 0;
}
