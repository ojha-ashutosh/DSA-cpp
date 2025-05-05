// cycle detection in undirected graph
#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class solutionbybfs{
    public:
    void create_abj_list(unordered_map<int,list<int>>&abj,vector<pair<int,int>>edges){
        for(int i=0;i<edges.size();i++){
            int u=edges[i].first;
            int v=edges[i].second;

            abj[u].push_back(v);
            abj[v].push_back(u);
        }
    }
    bool iscycle( unordered_map<int,list<int>>&abj,unordered_map<int,bool>&visited,int node){
        unordered_map<int,int>parant;
        queue<int>q;
        q.push(node);
        parant[node]=-1;
        visited[node]=1;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(int neighbour:abj[front]){
                if(visited[neighbour]==true && parant[front] != neighbour){
                    return true;//cycle detected 
                }
                else if(visited[neighbour]!= true){
                    q.push(neighbour);
                    visited[neighbour]=1;
                    parant[neighbour]=front;
                }
            }

        }return false;
    }
    bool soln(vector<pair<int,int>>edges,int vertex){
        unordered_map<int,list<int>>abj;
        create_abj_list(abj,edges);
        unordered_map<int,bool>visited;
        for(int i=1;i<=vertex;i++){
            if(!visited[i]){
                if(iscycle(abj,visited,i)){
                    return true;
                }
            }
        }
        return false;
    }
    
};
int main(){
    vector<pair<int,int>>edges={{1,2},{2,3},{3,4},{4,3}};
    int vertex =5;
    solutionbybfs abj;
    cout<<abj.soln(edges,vertex);
}