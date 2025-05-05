// Problem: Minimum Number of Perfect Squares to Form a Given Number

// Given a number n, find the minimum number of perfect squares that sum up to n. A perfect square is a 
// number that can be expressed as i^2 for some integer i (e.g., 1, 4, 9, 16, etc.).

// You need to write a function that computes the minimum number of perfect squares whose sum equals n.



#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
int MIN_NO_OF_perfect_sq_to_form_the_no(int n,vector<int>&dp){
    if(n==0){
        return 0;
        // 0 cant be form with any perfect sq
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=INT_MAX;
    // loop will run of imagin n=4 so i=1,2 but cant be 3 or more bec 3^2=9 >n(4)
    for(int i=1;i*i<=n;i++){
        int temp=i*i;
        ans=min(ans,1+MIN_NO_OF_perfect_sq_to_form_the_no(n-temp,dp));
    }
    dp[n]=ans;
    return dp[n];
}
int main(){
    int n=120;
    vector<int>dp(n+1,-1);
    cout<<MIN_NO_OF_perfect_sq_to_form_the_no(n,dp);
}