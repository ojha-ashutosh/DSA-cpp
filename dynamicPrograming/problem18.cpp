//Problem Statement: Pizza With 3n Slices 
// Problem Description:
// You are given a circular pizza that has been sliced into 3n equal slices. 
// Each slice has a different value representing the amount of tastiness you get from eating that slice.

// You need to select exactly n slices in such a way that:

// No two selected slices are adjacent (because you cannot eat two consecutive slices in a circular pizza).
// The sum of tastiness values of the selected slices is maximized

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int sol(vector<int>slices,int index,int n,vector<vector<int>>&dp){
    if(n==0 || index>=slices.size()){
        return 0;
    }
    if(dp[index][n]!=-1){
        return dp[index][n];
    }
    int eat=slices[index]+sol(slices,index+2,n-1,dp);
    int NOT_eat=0+sol(slices,index+1,n,dp);
    dp[index][n]=max(eat,NOT_eat);
    return dp[index][n];
}
int max_size_of_3n_pizza(vector<int>slices){
    int n=slices.size();
    vector<vector<int>>dp1(n,vector<int>(n/3 +1,-1));

    // when u eat 1st slices(cant eat last slice bec it is circular)
    int case_1=sol(slices,0,n/3,dp1);// you can only eat 3 slice in 3n pizza(n = total silce u can eat)

    vector<vector<int>>dp2(n,vector<int>(n/3 +1,-1));
    // when u dont eat 1st slices(can eat last slice bec it is circular)
    int case_2=sol(slices,1,n/3,dp2);
    return max(case_1,case_2);
}
int main() {
    vector<int> slices = {8, 9, 8, 6, 1, 1,7,54,5};
    cout << "Maximum Pizza Slices: " << max_size_of_3n_pizza(slices) << endl;
    return 0;
}
