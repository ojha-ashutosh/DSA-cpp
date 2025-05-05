// Problem Statement: Wildcard Pattern Matching
// Given two strings:

// sequence – the input string
// pattern – a pattern that may contain two special wildcard characters:
// ? matches any single character.
// * matches any sequence of characters (including empty sequence).
// Determine if the pattern matches the sequence completely.

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
bool sol(string sequence,string pattern,int i,int j,vector<vector<int>>&dp){
    if(i<0 && j<0){
        return true;
    }
    if(i>=0 && j<0){
        return false;
    }
    if(i<0 && j>=0){
        for(int k=0;k<=j;k++){
            if(pattern[k] != '*'){
                return false;
            }
        }
        return true;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    // match
    if(sequence[i]==pattern[j] || pattern[j]=='?'){
       return dp[i][j]= sol(sequence,pattern,i-1,j-1,dp);
    }
    else if(pattern[j]=='*'){
        return dp[i][j]= sol(sequence,pattern,i,j-1,dp) || sol(sequence,pattern,i-1,j,dp);
    }
    else{
        return dp[i][j]=false;
    }
}
bool is_match_mem(string sequence,string pattern){
    vector<vector<int>>dp(sequence.size()+1,vector<int>(pattern.size()+1,-1));
    return sol(sequence,pattern,sequence.size()-1,pattern.size()-1,dp);
}
bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = false;
    }
    for (int j = 1; j <= m; j++) {
        bool flag = true;
        for (int k = 1; k <= j; k++) {
            if (p[k-1] != '*') {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            } else if (p[j-1] == '*') {
                dp[i][j] =dp[i][j-1] || dp[i-1][j];                   
            } else {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}
int main() {
    string sequence = "abcde";
    string pattern = "a*c?e";

    if (isMatch(sequence, pattern)) {
        cout << "Match found!\n";
    } else {
        cout << "No match.\n";
    }
    
    return 0;
}