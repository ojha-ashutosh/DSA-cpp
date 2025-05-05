// The N Queens puzzle is the problem of placing N chess queens on an N N chessboard such that no two queens attack each other.
// Given an integer 'N', print all distinct solutions to the 'N' queen puzzle.

// 1. They share a row.
// Two queens on the same chessboard can attack each other if any of the below condition sapisfies:
// 2. They share a column.
// 3. They share a diagonal.
#include<iostream>
#include<vector>
using namespace std;
class N_queen
{
    public:
    void addsoln(vector<vector<int>>&board,vector<vector<int>>&ans,int n){
        vector<int> temp;
        for(auto i:board){
            for(auto j:i){
                temp.push_back(j);
            }
        }

        ans.push_back(temp);
    }
    bool issafe(int row,int col,vector<vector<int>>&board,int n){
        int i=row;
        int j=col;
        // dekho bhai kis col me ho usse peche he check krna hai 
        // hum ne es tarh code likha hai ki 1 col me 2 queen nhi aa sakte

        // same row
        while(j>=0){
           if(board[i][j]==1){
             return false;
           }
           j--;
        }

        int x=row;
        int y=col;
        // for diagonal
        // for upword left diagonal
        while(x>=0 && y>= 0){
            if(board[x][y]==1){
               return false;
            }
            x--;y--; 
        }
        // for lower left diagonal
        int p=row;
        int q=col;
        while(p<n && q>=0){
            if(board[p][q]==1){
               return false;
            }
            p++;q--; 
        }
        return true;
    }
    void solve(int col,vector<vector<int>>&board,vector<vector<int>>&ans,int n){
        if(col == n){
            addsoln(board,ans,n);
            return;
        }
        for(int row=0;row<n;row++){
            if(issafe(row,col,board,n)){
                board[row][col]=1;
                solve(col+1,board,ans,n);
                //vapas aane ke baad backtracking se
                board[row][col]=0;

            }
        }
    }
    vector<vector<int>> nQUEEN(int n){
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<int>>ans;
        solve(0,board,ans,n);
        return ans;
    }
};
int main() {
    N_queen obj;
    int n = 4; // Define the size of the chessboard
    vector<vector<int>> ans = obj.nQUEEN(n); // Get all solutions

    cout << "Solutions for " << n << "-Queens problem:" << endl;
    for (auto& solution : ans) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solution[i * n + j] << " "; // Properly print the matrix representation
            }
            cout << endl;
        }
        cout << endl; // Separate each solution
    }

    return 0;
}
