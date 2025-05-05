// Problem: Minimum Cost Tree from Leaf Values
// Given an array arr of positive integers representing the values of leaf nodes in a binary tree, your goal is to construct a binary tree such that:

// Each leaf node must come from arr (order is preserved).
// Each non-leaf node's value is the product of the maximum values of its left and right subtrees.
// The sum of all non-leaf node values should be minimized.

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <map>
using namespace std;
int sol(vector<int>&v,map<pair<int,int>,int>&maxi,int start,int end,vector<vector<int>>&dp){
    // leaf node
    if(start==end){
        return 0;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    int ans=INT_MAX;
    for(int i=start;i<end;i++){
        ans=min(ans,maxi[{start,i}]*maxi[{i+1,end}]+sol(v,maxi,start,i,dp)+sol(v,maxi,i+1,end,dp));
    }
    return dp[start][end]=ans;
}
int min_sum_leafNODE(vector<int>v){
    map<pair<int,int>,int>maxi;
    for(int i=0;i<v.size();i++){
        maxi[{i,i}]=v[i];
        for(int j=i+1;j<v.size();j++){
            maxi[{i,j}]=max(v[j],maxi[{i,j-1}]);
        }
    }
    int n=v.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return sol(v,maxi,0,v.size()-1,dp);
}
int main() {
    vector<int> v = {6, 2, 4};
    cout << "Minimum sum of non-leaf node values: " << min_sum_leafNODE(v) << endl;
    return 0;
}