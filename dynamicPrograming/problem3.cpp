// Question: You are given a vector `coin` where each element represents the denomination of a coin. 
// Your task is to determine the minimum number of coins required to make up a given target sum. 
// If it is not possible to make the target sum, return `-1`. 
// You can assume you have an infinite number of coins for each denomination. 


#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int coins_recursivly(vector<int>coin,int target){
     if(target==0) return 0;
     if(target<0) return INT_MAX;
     
     int mini=INT_MAX;
     for(int i=0;i<coin.size();i++){
        int ans=coins_recursivly(coin,target-coin[i]);
        if(ans!=INT_MAX){
            mini=min(mini,1+ans);
        }
     }
     return mini;
}
int coins_topdownAproch(vector<int>coin,int target,vector<int>&dp){
     if(target==0) return 0;
     if(target<0) return INT_MAX;
     
     if(dp[target]!=-1) return dp[target];


     int mini=INT_MAX;
     for(int i=0;i<coin.size();i++){
        int ans=coins_topdownAproch(coin,target-coin[i],dp);
        if(ans!=INT_MAX){
            mini=min(mini,1+ans);
        }
     }
     dp[target]=mini;
     return mini;
}
int coins_bottomUPAproch(vector<int>coin,int target){
     vector<int>dp(target+1,INT_MAX);
     dp[0]=0;
     for(int i=1;i<=target;i++){
        for(int j=0;j<coin.size();j++){
            if(i-coin[j]>=0 && dp[i-coin[j]] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i - coin[j]]);
            }
        }
     }
     return dp[target];
}
int min_coin(vector<int>coin,int target){
    // int ans=coins_recursivly(coin,target);
    // if(ans==INT_MAX){
    //     return -1;
    // }
    vector<int>dp(target+1,-1);

    int ans1=coins_topdownAproch(coin,target,dp);
    if(ans1==INT_MAX){
        return -1;
    }
    return ans1;

    // int ans2=coins_bottomUPAproch(coin,target);
    // if(ans2==INT_MAX){
    //     return -1;
    // }
    // return ans2;
}
int main() {
    vector<int> coin = {1, 2, 5};
    int target = 11;
    cout << min_coin(coin, target) << endl;
    return 0;
}