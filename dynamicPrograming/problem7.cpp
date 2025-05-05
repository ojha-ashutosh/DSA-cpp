// count derangements
// same place pr nhi ho sakta 

#include<iostream>
#include<vector>
using namespace std;

int cd_topdown(int n,vector<int>&dp){
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    
    if(dp[n]!=-1)
        return dp[n];
    
    dp[n]=(n-1)*(cd_topdown(n-1,dp)+cd_topdown(n-2,dp));
    return dp[n];
}
int cd_bottomup(int n){
    vector<int>dp(n+1,-1);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}
int spaceOptimization(int n){
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    
    int prev2=0;
    int prev1=1;
    for(int i=3;i<=n;i++){
        int curr=(i-1)*(prev1+prev2);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main(){
    int n=10;
    vector<int>dp(n+1,-1);
    cout<<cd_topdown(n,dp)<<endl;

    cout<<cd_bottomup(n)<<endl;

    cout<<spaceOptimization(10);
}
