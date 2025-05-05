// Problem Statement: Number of Ways to Get Target Sum Using Dice
// You are given dice number of dice, each having face number of faces (numbered from 1 to face). Your task is to determine the number of ways to roll the dice so that the sum of the outcomes equals a given target.

// Constraints:
// 1 ≤ dice ≤ 30 (Total number of dice)
// 1 ≤ face ≤ 20 (Number of faces on each die)
// 1 ≤ target ≤ 1000 (Desired target sum)

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int sol(int dice,int face,int target,vector<vector<int>>&dp){
    // base case
    if(target<0){
        return 0;
    }
    if(dice==0 && target != 0){
        return 0;
    }
    if(target==0 && dice != 0){
        return 0;
    }
    if(target==0 && dice == 0){
        return 1;
    }
    if(dp[dice][target]!=-1){
        return dp[dice][target];
    }
    int ans=0;
    for(int i=1;i<=face;i++){
        ans=ans+sol(dice-1,face,target-i,dp);
    }
    return dp[dice][target]=ans;
}
int dice_target_sum(int dice,int face,int target){
    vector<vector<int>>dp(dice+1,vector<int>(target+1,-1));
    // dice plus 1 bec we have to store base case dice =0
    return sol(dice,face,target,dp);
}
int main() {
    int dice = 4, face = 6, target = 12;
    cout << "Number of Ways to Get Target Sum: " << dice_target_sum(dice, face, target) << endl;
    return 0;
}