#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;
class Graphbyvector {
private:
    vector<vector<int>> adjList;

public:
    // Constructor to initialize the graph with a given number of vertices
    Graphbyvector(int vertices) {
        adjList.resize(vertices);
    }

    // Add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Uncomment this line for undirected graph
    }

    // Print the graph
    void printGraph(){
        for (int i = 0; i < adjList.size(); ++i) {
            cout << "Vertex " << i << ":";
            for (int j : adjList[i]) {
                cout << " -> " << j;
            }
            cout << endl;
        }
    }
};
class Graphbymap
{
  public:
        unordered_map<int,list<int>>abjlist;
        void insertedge(int u,int v,bool direction){
            // direction=0 ->undirected graph
            // direction=1 ->directed graph
            abjlist[u].push_back(v);
            if(direction==false){
                // undirected
                abjlist[v].push_back(v);
            }
        }
        void printAbjList(){
            for(auto i:abjlist){
                cout<<i.first<<"-> ";
                for(auto j:i.second){
                    cout<<j<<",";
                }cout<<endl;
            }
        }
};
int main(){
    Graphbymap g;
    // inserting edge
    // undirected
    g.insertedge(0, 1, false);
    g.insertedge(0, 4, false);
    g.insertedge(1, 4, false);
    g.insertedge(1, 3, false);
    g.insertedge(3, 4, false);
    g.insertedge(1, 2, false);
    // printing
    g.printAbjList();

    cout<<endl<<endl;
    Graphbyvector gv(5);

    // Add edges
    gv.addEdge(0, 1);
    gv.addEdge(0, 4);
    gv.addEdge(1, 2);
    gv.addEdge(1, 3);
    gv.addEdge(1, 4);
    gv.addEdge(2, 3);
    gv.addEdge(3, 4);

    // Print the graph
    gv.printGraph();

    return 0;
}