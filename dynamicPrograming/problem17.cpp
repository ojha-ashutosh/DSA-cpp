// Problem Statement: Longest Increasing Subsequence (LIS) 
// Problem Description:
// Given an array of integers v, find the length of the longest increasing subsequence (LIS). A subsequence is a sequence derived from the array by deleting some or no elements without changing the order of the remaining elements. An increasing subsequence is a subsequence where the elements are in strictly increasing order.
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int sol(int n,vector<int>v,int curr_pos,int prev_pos,vector<vector<int>>&dp){
    if(curr_pos>=n){
        return 0;
    }
    if(dp[curr_pos][prev_pos+1]!=-1){
        // prev-Pos+1 bec prev_pos is -1 so it can be a valid index
        return dp[curr_pos][prev_pos+1];
    }
    // include case
    int include=0;
    if(prev_pos == -1 || v[curr_pos]>v[prev_pos]){
        include=1+sol(n,v,curr_pos+1,curr_pos,dp);
    }
    int exclude=0+sol(n,v,curr_pos+1,prev_pos,dp);
    dp[curr_pos][prev_pos+1]=max(include,exclude);
    return dp[curr_pos][prev_pos+1];
}
int longest_increasing_seq(vector<int>v,int n){
    vector<vector<int>>dp(n ,vector<int>(n+1,-1));
    return sol(n,v,0,-1,dp);
}
int tabulation(vector<int>& v) {
    int n=v.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int curr=n-1;curr>=0;curr--)
    {
        for(int prev=curr-1;prev>=-1;prev--)
        {
        int include=0;
        if(prev==-1 || v[curr]>v[prev])
        {
            include=1+dp[curr+1][curr+1];
        }
        int exclude=dp[curr+1][prev+1];
        dp[curr][prev+1]=max(include,exclude);
        }
    }
    return dp[0][-1+1];
}
int main() {
    vector<int> v = {10, 22, 9, 33, 21, 50, 41, 60};
    int n=v.size();
    cout << "Longest Increasing Subsequence Length: " << longest_increasing_seq(v,n) << endl;
    cout<<"\n tabulation "<<tabulation(v);
    return 0;
}