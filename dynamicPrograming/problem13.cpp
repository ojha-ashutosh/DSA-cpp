// largest sq area in matrix
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int sol(int n,int m,vector<vector<int>>matrix,int i,int j,int &maxi,vector<vector<int>>&dp){
    if(i>=n || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int right=sol(n,m,matrix,i,j+1,maxi,dp);
    int diagonal=sol(n,m,matrix,i+1,j+1,maxi,dp);
    int down=sol(n,m,matrix,i+1,j,maxi,dp);

    if(matrix[i][j]==1){
        dp[i][j]=1+min(right,min(diagonal,down));
        maxi=max(maxi,dp[i][j]);
        return dp[i][j];
    }else{
        dp[i][j]=0;
        return dp[i][j];
    }
    
}
int largest_sq(vector<vector<int>>matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    
    int maxi=0;
    vector<vector<int>>dp(n,vector<int>(m+1,-1));
    sol(n,m,matrix,0,0,maxi,dp);
    return maxi;
}
int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 1, 0, 0}
    };

    cout << "Largest Square Size: " << largest_sq(matrix) << endl;
    return 0;
}