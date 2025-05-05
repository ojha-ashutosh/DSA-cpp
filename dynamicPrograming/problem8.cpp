// Lecture 109: Painting Fence Algorithm || DP Series

// only two abjusent fance have same color 

// The **Painting Fence Algorithm** is a dynamic programming problem 
// where you are tasked with painting a fence with `n` posts using `k` 
// different colors, with the constraint that no two adjacent posts can 
// have the same color. The goal is to determine the number of ways to 
// paint the fence, following this restriction. The problem is solved by
//  breaking it down into smaller subproblems: for each post, you can 
//  either paint it the same color as the previous one or a different
//   color. Using dynamic programming, the solution involves maintaining 
//   a state that tracks the number of ways to paint the fence up to a
//    certain post, either with the same color as the previous one or a 
//    different color, and applying the recurrence relation to compute the result.
//     The time complexity of the solution is `O(n * k)`, where `n` is the number of 
//     posts and `k` is the number of colors.
#include<iostream>
#include<vector>
using namespace std;
int solve_topDOWN(int n,int k,vector<int>&dp){
    if(n==1){
        return k;
    }
    if(n==2){
        // same colur both+ both oposite color
        return k+(k*(k-1));
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = (k - 1) * (solve_topDOWN(n - 2, k, dp) + solve_topDOWN(n - 1, k, dp));
    return dp[n];
}
int solve_bottom_up(int n,int k){
    vector<int>dp(n+1,-1);
    dp[1]=k;
    dp[2]=k+(k*(k-1));
    for(int i=3;i<=n;i++){
        dp[i]=(i-1)*(dp[i-2]+dp[i-1]);
    }
    return dp[n];
}
int spaceoptimize(int n,int k){
    int prev2=k;
    int prev1=k+(k*(k-1));
    for(int i=3;i<=n;i++){
        int temp=(i-1)*(prev2+prev1);
        prev2=prev1;
        prev1=temp;
    }
    return prev1;
}
int solve(int n,int k){
    vector<int>dp(n+1,-1);
    // return solve_topDOWN(n,k,dp);
    

    // return solve_bottom_up(n,k);

    return spaceoptimize(n,k);
}
int main() {
    int n = 5;  // Example n(no of fance to paint)
    int k = 3;  // Example k(no of colour)
    cout << "Solution: " << solve(n, k) << endl;
    return 0;
}