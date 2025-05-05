// topological sort
// u->v hai abj list me tho u hamesha v se peche aana chahiye
// ye cyclic graphs ke liye nhi banta bec order maintain nhi ho pata
// (DAG ->directed acylic graph )
#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <list>
#include <queue>
using namespace std;
class soln
{
public:
    void createabj(vector<pair<int, int>> edges, unordered_map<int, list<int>> &abjlist)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;

            // directed

            abjlist[u].push_back(v);
        }
    }
    void topo(unordered_map<int, list<int>> abjlist, stack<int> &s, vector<bool> &visited, int node)
    {
        visited[node] = true;
        for (auto i : abjlist[node])
        {
            if (visited[i] == false)
            {
                topo(abjlist, s, visited, i);
            }
        }
        // we have to push the element in stack after the last recursive call;
        s.push(node);
    }
    vector<int> problem(vector<pair<int, int>> edges, int vertics)
    {
        unordered_map<int, list<int>> abjlist;
        createabj(edges, abjlist);
        vector<bool> visited(vertics, false);
        stack<int> s;
        for (int i = 0; i < vertics; i++)
        {
            if (!visited[i])
            {
                topo(abjlist, s, visited, i);
            }
        }

        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

// khan`s algorithm
// doing same problem of topological sort with bfs
// DAG

// steps
// 1->find indegree of all the node
// 2->push node having 1 indegree in queue
// 3->perform bfs with some changes
// 4->maintain indegree
class khanALGO
{
public:
    vector<int> topoWITHbfs(vector<pair<int, int>> edges, int vertices)
    {
        unordered_map<int, list<int>> abj;
        for (int i = 0; i < vertices; i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;

            abj[u].push_back(v);
        }

        vector<int> indegree(vertices);
        for (int i = 0; i < vertices; i++)
        {
            for (auto neighbore : abj[i])
            {
                indegree[neighbore]++;
            }
        }
        vector<int>ans;
        queue<int> q;
        for (int i = 0; i < vertices; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            // strore in vector
            ans.push_back(front);
            for (int neighbore : abj[front])
            {
                indegree[neighbore]--;
                if (indegree[neighbore] == 0)
                {
                    q.push(neighbore);
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {5, 6}};
    soln s;
    khanALGO k;
    vector<int> ans = s.problem(edges, 7);
    vector<int> ans1 = k.topoWITHbfs(edges, 7);

    for (int vertex : ans)
    {
        cout << vertex << " ";
    }
    cout << endl;
    for (int vertex : ans1)
    {
        cout << vertex << " ";
    }
}