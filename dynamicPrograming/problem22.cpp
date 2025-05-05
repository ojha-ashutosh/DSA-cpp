// total no of independent(uniqe) binary search tree in given no node
// for n=3 ans is 5
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int sol(int n,vector<int>&dp){
    if(n==0 || n==1){
        return 1;
        // for n=0 1 bst is there having null node
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=sol(i-1,dp)*sol(n-i,dp);
    }
    return dp[n]=ans;
}
int total_unique_bst(int n){
    vector<int>dp(n+1,-1);
    return sol(n,dp);
}
int main(){
    int n;
    cin>>n;
    cout<<"total no of independent(uniqe) binary search tree in given no node "<<total_unique_bst(n);
}