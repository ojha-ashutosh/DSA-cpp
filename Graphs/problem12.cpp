// kosaraju's algorithm for strongly connected component(scc)
// strongly connected component in graph is the part in which we can vist each node of that part by all node

// steps
// 1->topologcal sort
// 2->transpose of graph
// 3->dfs call in topological order

#include <iostream>
#include <stack>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
class kosarajualgorithm
{
public:
    void dfs(int node, stack<int> &s, unordered_map<int, list<int>> abj, unordered_map<int, bool> &visited)
    {
        visited[node] = 1;
        for (auto neighbour : abj[node])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, s, abj, visited);
            }
        }
        s.push(node);
    }
    void revdfs(int node, unordered_map<int, bool> &visited,unordered_map<int,list<int>>transpose,vector<int>&v){
        visited[node]=true;
        v.push_back(node);
        for(auto neighbour:transpose[node]){
            if(visited[neighbour]==false){
                revdfs(neighbour,visited,transpose,v);
            }
        }
    }
    pair<int,vector<vector<int>>> scc(vector<vector<int>> edges, int e, int v)
    {
        unordered_map<int, list<int>> abj;
        for (int i = 0; i < e; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            abj[u].push_back(v);
        }
        unordered_map<int, bool> visited;
        stack<int> s;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs(i, s, abj, visited);
            }
        }

        unordered_map<int,list<int>>transpose;
        for(int i=0;i<v;i++){
            //making visited false
            visited[i]=0;
            for(auto neighbour:abj[i]){
                transpose[neighbour].push_back(i);
            }
        }


        // dfs call for topological order
        int count=0;
        vector<vector<int>>res;
        while(!s.empty()){
            int top=s.top();
            s.pop();
            if(!visited[top]){
                count++;
                // this will count no of SCC
                vector<int>temp;
                revdfs(top,visited,transpose,temp);
                res.push_back(temp);
            }
        }
        return make_pair(count,res);
    }
};
int main() {
    int v = 5;
    int e = 5;

    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}
    };

    kosarajualgorithm ka;
    pair<int, vector<vector<int>>> result = ka.scc(edges, e, v);

    int count = result.first;
    vector<vector<int>> sccs = result.second;

    cout << "Number of Strongly Connected Components (SCCs): " << count << endl;
    cout << "The Strongly Connected Components are:" << endl;
    for (const auto &component : sccs) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
