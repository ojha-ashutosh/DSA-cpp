// Problem: Longest Palindromic Subsequence (LPS)
// Problem Statement:
// Given a string s, find the length of the longest palindromic subsequence (LPS). 
// A subsequence is a sequence that can be derived from another string by deleting some characters without changing the order.
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
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
int longest_palindromic_subsequence(string a){
    string b=a;
    reverse(a.begin(), a.end()); 
    return longest_common_subsequence(a,b);
}
int main() {
    string s = "bbbab";
    cout << "Longest Palindromic Subsequence: " << longest_palindromic_subsequence(s) << endl;
    return 0;
}