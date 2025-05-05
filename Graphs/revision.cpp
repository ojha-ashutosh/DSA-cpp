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
        visited[node]=true;
        disc[node]=low[node]=timer++;
        for(auto n:abj[node]){
            if(n==parant){
                continue;
            }
            if(!visited[n]){
                dfs(n,node,timer,disc,low,result,abj,visited);
                low[node]=min(low[node],low[n]);
                if(disc[node]<low[n]){
                    vector<int>ans;
                    ans.push_back(node);
                    ans.push_back(n);
                    result.push_back(ans);
                }
            }else{
                // back edge
                low[node]=min(disc[n],low[node]);
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

        int timer=0;
        int parent=-1;
        vector<int>disc(v,-1);
        vector<int>low(v,-1);
        unordered_map<int,bool>visited;
        
        vector<vector<int>> result;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs(i,parent,timer,disc,low,result,abj,visited);
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
