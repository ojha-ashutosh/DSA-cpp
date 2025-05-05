// kruskal's algo
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class kruskal
{
public:
    //   disjoint set
    void makeset(vector<int> &parant, vector<int> &rank, int n)
    {
        for (int i = 0; i < n; i++)
        {
            parant[i] = i;
            rank[i] = 0;
        }
    }
    int findparants(vector<int> &parant, int n)
    {
        if (parant[n] == n)
        {
            return n;
        }
        return parant[n] = findparants(parant, parant[n]); // path comparation
    }
    void unionset(int u, int v, vector<int> &parant, vector<int> &rank)
    {
        u = findparants(parant, u);
        v = findparants(parant, v);
        if (rank[u] > rank[v])
        {
            parant[v] = u;
        }
        else if (rank[u] < rank[v])
        {
            parant[u] = v;
        }
        else
        {
            parant[v] = u;
            rank[u]++;
        }
    }

    int minimumspaningtree(vector<vector<int>>edges,int n){
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2]; // Compare weights (third element of each edge)
        });
        vector<int>parant(n);
        vector<int>rank(n);
        makeset(parant,rank,n);

        int minimumweight=0;

        for(int i=0;i<edges.size();i++){
            int u=findparants(parant,edges[i][0]);
            int v=findparants(parant,edges[i][1]);
            int w=edges[i][2];

            if(u!=v)//not conected (disjoint)
            {
               minimumweight+=w;
               unionset(u,v,parant,rank);
            }
        }
        return minimumweight;
    }
};
int main()
{
    vector<vector<int>> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    int n = 4; // Number of nodes (0 to 3)

    kruskal k;
    int minimumWeight = k.minimumspaningtree(edges, n);

    cout << "The weight of the Minimum Spanning Tree is: " << minimumWeight << endl;

    return 0;
}
