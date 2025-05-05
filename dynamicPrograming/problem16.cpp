// reducing dish
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int sol(vector<int>&satisfaction,int index,int time,vector<vector<int>>&dp,int n){
    if(index>=n){
        return 0;
    }
    if(dp[index][time]!=-1){
        return dp[index][time];
    }
    int include =satisfaction[index]*time +sol(satisfaction,index+1,time+1,dp,n);
    int exclude=sol(satisfaction,index+1,time,dp,n);

    dp[index][time]=max(include,exclude);
    return dp[index][time];

}
int max_satisfaction(vector<int>satisfaction){
    int n=satisfaction.size();
    sort(satisfaction.begin(),satisfaction.end());
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return sol(satisfaction,0,1,dp,n);
}
int main() {
    vector<int> satisfaction = {-1, -8, 0, 5, -9,5};
    cout << "Maximum Satisfaction: " << max_satisfaction(satisfaction) << endl;
    return 0;
}