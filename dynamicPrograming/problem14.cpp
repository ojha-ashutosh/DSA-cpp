// minimum product of traingle in polygon
// min score triangulation of polygon
#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
int sol(int i,int j,vector<int>value,vector<vector<int>>&dp){
    if(i+1==j){
        // only 2 point no traingle is formed
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
    ans=min(ans,value[i]*value[j]*value[k]+sol(i,k,value,dp)+sol(k,j,value,dp));
    }
    dp[i][j]=ans;
    return dp[i][j];
}
int min_score_triangle(vector<int>value){
    int n=value.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return sol(0,n-1,value,dp);
}
int main() {
    vector<int> value = {1, 2, 3,4};  // Example input
    cout << "Minimum Score Triangulation: " << min_score_triangle(value) << endl;
    return 0;
}
