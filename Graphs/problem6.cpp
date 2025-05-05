// sortest parth form source node in a acyclic weighted graph
#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<stack>
#include<limits.h>
using namespace std;
class Graph
{
    public:
    unordered_map<int,list<pair<int,int>>>adj;
    void addEdges(int u,int v,int weight){
        pair<int,int> n=make_pair(v,weight);
        adj[u].push_back(n);
    }

    void printAdj() {
       for(auto i:adj){
          cout<<i.first<<"->";
          for(auto j:i.second){
             cout<<"("<<j.first<<","<<j.second<<")";
          }cout<<endl;
       } 
        
    }
    // topo sort by dfs
    void dfs(int node,unordered_map<int,bool>&visited,stack<int>&s){
        visited[node]=1;
        for(auto i:adj[node]){
            if(!visited[i.first]){
                dfs(i.first,visited,s);
            }
        }
        s.push(node);
    }
    void getsortestdist(vector<int>&sortestdist,int source,stack<int>s){
        sortestdist[source]=0;
        while(!s.empty()){
            int topo=s.top();
            s.pop();
            if(sortestdist[topo]!=INT_MAX){
                for(auto i:adj[topo]){
                    if((sortestdist[topo]+i.second)<sortestdist[i.first]){
                           sortestdist[i.first]= sortestdist[topo]+i.second;
                    }
                }
            }
        }
    }
};
int main(){
    Graph g;
    g.addEdges(0,1,5);
    g.addEdges(0,2,3);
    g.addEdges(1,2,2);
    g.addEdges(1,3,6);
    g.addEdges(2,3,7);
    g.addEdges(2,4,4);
    g.addEdges(2,5,2);
    g.addEdges(3,4,-1);
    g.addEdges(4,5,-2);
    // g.printAdj();
    
    // topo logical sort
    unordered_map<int,bool>visited;
    stack<int>s;
    for(int i=0;i<6;i++){
       if(!visited[i]){
          g.dfs(i,visited,s);
       }
    }
    vector<int>sortestDIST(6,INT_MAX);
    int source=1;
    g.getsortestdist(sortestDIST,source,s);
    for(auto i:sortestDIST){
        cout<<i<<" ";
    }
}