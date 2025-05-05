// Guess Number Higher or Lower II
// Given a number n, you have to guess a number between 1 and n. Each time you make a guess x, you have to pay x dollars.
//  If your guess is wrong, you will be told whether the number is higher or lower, and you continue guessing.

// The goal is to determine the minimum amount of money required to guarantee a win, assuming you play optimally.


#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int sol(int start,int end,vector<vector<int>>&dp){
    if(start>=end){
        return 0;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    int mini=INT_MAX;
    for(int i=start;i<=end;i++){
        mini=min(mini,(i+max(sol(start,i-1,dp),sol(i+1,end,dp))));
        //we take max in recursive call bec we take the worst case that is we guess
        // the worng no....so we can obtain the maximum value in worst case 
    }
    return dp[start][end]=mini;
}
int min_amt_for_guessing_the_no(int n){
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return sol(1,n,dp);
}

int main() {
    int n;
    cin >> n;
    cout << "Minimum amount to guarantee a win: " << min_amt_for_guessing_the_no(n) << endl;
    return 0;
}