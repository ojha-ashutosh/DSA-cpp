// Question: Total Number of Ways to Reach a Target Sum
// You are given an array of positive integers nums and an integer target. 
// Your task is to determine the total number of ways to achieve the target sum by 
// repeatedly using elements from the nums array. Each element in nums can be used 
// any number of times.
#include<iostream>
#include<vector>
using namespace std;
int TOTAL_WAYS(vector<int>nums,int target,vector<int>&dp){
    if(target==0){
        // no of ways to make 0 is do not take any coin (1 way)
        return 1;
    }
    if(target<0){
        return 0;
    }
    if(dp[target]!=-1){
        return dp[target];
    }
    int ans=0;
    for(int i=0;i<nums.size();i++){
        ans+=TOTAL_WAYS(nums,target-nums[i],dp);     
    }
    dp[target]=ans;
    return dp[target];
}
int main(){
    vector<int>nums={1,2};
    int target=3;
    vector<int>dp(target+1,-1);
    cout<<TOTAL_WAYS(nums,target,dp);
}