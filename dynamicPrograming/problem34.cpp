// Your code is attempting to solve the Longest Common Subsequence (LCS) 
// Problem, which is a classic problem in dynamic programming. Here’s a detailed problem description:

// Problem Statement:
// Given two strings A and B, find the length of the longest subsequence 
// that appears in both strings in the same order (but not necessarily consecutively).
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int longestCommonSubsequence(string t1, string t2) {
    int n=t1.size();int m=t2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    // here we loop till n and m bec we haveto takkel -1 in base case
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=m;j++) dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(t1[i-1]==t2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int sol(string a,string b,int n,int m,int i,int j,vector<vector<int>> &dp){
    if(i>=n || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(a[i]==b[j]){
        ans= 1+sol(a,b,n,m,i+1,j+1,dp);
    }else{
        ans= max(sol(a,b,n,m,i+1,j,dp),sol(a,b,n,m,i,j+1,dp));
    }
    return dp[i][j]=ans;
}
int longest_common_subsequence(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m, -1));
    return sol(a,b,n,m,0,0,dp);
}
int main() {
    string a = "ashutosh", b = "satyam";
    cout << longest_common_subsequence(a, b) << endl;
    return 0;
}