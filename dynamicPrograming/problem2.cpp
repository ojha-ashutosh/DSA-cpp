// Question: Given a vector `cost` where cost[i] is the cost of the i-th step on a staircase, 
// you need to find the minimum cost to reach the top of the staircase. 
// You can either start from step 0 or step 1 and move to the top by taking 1 or 2 steps at a time.
// Implement a recursive solution to solve this problem.

#include <iostream>
#include <vector>
using namespace std;

int mincost(vector<int> cost, int n) {
    // adding cost till f(n-1)

    if (n == 0) return cost[0]; // start from 0th stair
    if (n == 1) return cost[1]; // start from 1st stair

    int ans = cost[n]+min(mincost(cost, n - 1) , mincost(cost, n - 2));
    return ans;
}
// by dp tow-down
int mincost_dp_topdown_approch(vector<int> cost,vector<int>&dp, int n) {
    // adding cost till f(n-1)

    if (n == 0) return cost[0]; // start from 0th stair
    if (n == 1) return cost[1]; // start from 1st stair
    
    if(dp[n]!=-1) return dp[n];

    dp[n] = cost[n]+min(mincost_dp_topdown_approch(cost,dp, n - 1) , mincost_dp_topdown_approch(cost,dp, n - 2));
    return dp[n];
}
int mincost_dp_bottomUP_approch(vector<int>cost,int n){
    vector<int>dp(n+1,-1);

    // base case
    dp[0]=cost[0];
    dp[1]=cost[1];

    // loop for 2 ->n-1
    for(int i=2;i<n;i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}
int space_optimization(vector<int>cost,int n){
    int prev2=cost[0];
    int prev1=cost[1];
    for(int i=2;i<n;i++){
        int curr=cost[i]+min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
    }
    return min(prev1,prev2);
}
int main() {

    // by recursion
    vector<int> cost = {10, 15, 20,5,100};
    int n = cost.size();
    cout << "Minimum cost to reach the top: " ;
    // min cost of f(n)->no extra cost added
    cout<< min(mincost(cost, n - 1), mincost(cost, n - 2)) << endl;
    

    // by dp
    vector<int>dp(n+1,-1);
    cout << "Minimum cost to reach the top by dp: " ;
    // min cost of f(n)->no extra cost added
    cout<< min(mincost_dp_topdown_approch(cost,dp, n - 1), mincost_dp_topdown_approch(cost,dp,n - 2)) << endl;
    
    // By bottom-up DP
    cout << "Minimum cost to reach the top (Bottom-Up DP): ";
    cout << mincost_dp_bottomUP_approch(cost, n) << endl;

    // Space-optimized DP solution
    cout << "Minimum cost to reach the top (Space Optimized): ";
    cout << space_optimization(cost, n) << endl;
    return 0;
}
