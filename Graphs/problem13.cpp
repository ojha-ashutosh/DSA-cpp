// Bellman ford algo
// it wiil work on negative weight but not on negative cycle
// we can find that -ve cycle exit or not(so we cant apply this algo in negative cycle for finding sortest path but we can check that -ve cycle is present or not)
// if no -ve cycle we can find sortest path
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class BFA
{ 
    public:
    int soln(int n, int e, int source, int destination, vector<vector<int>> edges)
    {
        vector<int> dist(n, INT_MAX);
        dist[source] = 0;
        // apply formula n-1 time
        for (int i = 0; i < n - 1; i++)
        {
            // traverse all node
            for (int i = 0; i < n; i++)
            {
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];

                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        //  now check for -ve cycle

        // if flag become true it means the value is chnaging afer n-1 time of loop that is there is a negative cycle and we can not find sortest path
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                flag = true;
            }
        }
        if(flag==false){
            return dist[destination];
        }else{
            return -1;
        }
    }
};
int main() {
    int v = 5, e = 8, source = 0, destination = 2;

    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    BFA bfa;
    int result = bfa.soln(v, e, source, destination, edges);

    if (result != -1) {
        cout << "Shortest path from source " << source 
             << " to destination " << destination << " is: " << result << endl;
    } else {
        cout << "Graph contains a negative cycle. Shortest path cannot be determined." << endl;
    }

    return 0;
}
