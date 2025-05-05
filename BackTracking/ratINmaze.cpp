#include<iostream>
#include<vector>
using namespace std;
class rat_in_maze
{
    public:
    bool issafe(int newi,int newj,vector<vector<bool>> &visited,vector<vector<int>>&arr,int n){
        if((newi>=0 && newi<n) && (newj>=0 && newj<n) && visited[newi][newj]!=1 && arr[newi][newj]==1){
            return true;
        }else{
            return false;
        }
    }
    void findpath(int i,int j,vector<vector<int>>&arr,vector<vector<bool>> &visited,string path,vector<string>&ans,int n){
        // destination
        if(i==n-1 && j==n-1){
            ans.push_back(path);
            return;
        }
        // 4 movement ........... Down-> Left-> Right-> Up
        // mark visited to current i and j
        visited[i][j]=1;
        // down
        if(issafe(i+1,j,visited,arr,n)){
            findpath(i+1,j,arr,visited,path+'D',ans,n);
        }
        // left
        if(issafe(i,j-1,visited,arr,n)){
            findpath(i,j-1,arr,visited,path+'L',ans,n);
        }

        // right
        if(issafe(i,j+1,visited,arr,n)){
            findpath(i,j+1,arr,visited,path+'R',ans,n);
        }

        // up
        if(issafe(i-1,j,visited,arr,n)){
            findpath(i-1,j,arr,visited,path+'U',ans,n);
        }
        // after backtracking unmark visited to i and j
        visited[i][j]=0;

    }
    vector<string> solve(vector<vector<int>>&arr,int n){     
        string path="";
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        vector<string>ans;
        // start path is zero
        if(arr[0][0]==0){
            return ans;
        }
        findpath(0,0,arr,visited,path,ans,n);
        return ans;
    }
};
int main(){
    vector<vector<int>>arr={{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};
    int n=4;
    rat_in_maze obj;
    vector<string> ans=obj.solve(arr,n);
    for(auto i:ans){
        cout<<i<<"    ";
    }

}