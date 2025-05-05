// shorted path of unweighted graphs
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>
using namespace std;
class solve{
   public:
   vector<int> sortestPath(vector<pair<int,int>>edges,int source,int distination){
       unordered_map<int,list<int>>abj;
       for(int i=0;i<edges.size();i++){
         int u=edges[i].first;
         int v=edges[i].second;

        //  undirected
          abj[u].push_back(v);
          abj[v].push_back(u);
       }    
        queue<int>q;
        unordered_map<int,bool>visited;
        unordered_map<int,int>parant;
        //do bfs
        q.push(source);
        parant[source]=-1;
        visited[source]=1;
        while (!q.empty())
        {
            int front=q.front();
            q.pop();
            for(auto i:abj[front]){
                if(visited[i]==false){
                    visited[i]=true;
                    parant[i]=front;
                    q.push(i);
                }
            }
        }
        vector<int>ans;
        ans.push_back(distination);
        int i=distination;
        while(i!=source){
            i=parant[i];
            ans.push_back(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
   }
};
int main(){
    vector<pair<int,int>>edges={
        {1,2},{1,3},{1,4},{2,5},{5,8},{3,8},{4,6},{6,7},{7,8}
    };
    solve s;
    vector<int>ans=s.sortestPath(edges,2,8);
    for(int i:ans){
        cout<<i<<"->";
    }
}