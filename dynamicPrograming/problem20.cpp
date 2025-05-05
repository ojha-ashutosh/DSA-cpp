// Problem Statement: Equal Partition Subset Sum
// Problem Description:
// You are given an array v of n positive integers. Your task is to determine 
// if it is possible to partition the array into two subsets such that the sum of elements in both subsets is equal.

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
bool sol(vector<int>v,int n,int index,int target,vector<vector<int>>&dp){
    if(index>=n){
        return 0;
    }
    if(target==0){
        return true;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    bool include=sol(v,n,index+1,target-v[index],dp);
    bool exclude=sol(v,n,index+1,target,dp);

    return dp[index][target]=(include||exclude);
}
bool eq_partition(vector<int>v){
    int n=v.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }
    // if sum is odd we cant divide it in two subset with equal sum
    if(sum % 2 != 0){
        return false;
    }
    int target=sum/2;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    // sol fn will give a one subset that contain helf sum that means other one have the helf sum (so get divided into two partitiin)
    return sol(v,n,0,target,dp);
}
int main() {
    vector<int> v = {17, 5, 11, 5,6};
    cout << (eq_partition(v) ? "true" : "false") << endl; 
    return 0;
}