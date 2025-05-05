#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int sol(vector<int>&v1,vector<int>&v2,bool swaped,int index,vector<vector<int>>&dp){
    if(index >= v1.size()){
        return 0;
    }
    if(dp[index][swaped]!=-1){
        return dp[index][swaped];
    }
    int ans=INT_MAX;
    int prev1=v1[index-1];
    int prev2=v2[index-1];

    if(swaped){
        swap(prev1,prev2);
    }
    // not swap already in stricly incresing order
    if(v1[index]>prev1 && v2[index]>prev2){
        ans=sol(v1,v2,0,index+1,dp);
    }
    // swap
    if(v1[index]>prev2 && v2[index]>prev1){
        ans=min(ans,1+sol(v1,v2,1,index+1,dp));
    }
    return dp[index][swaped]=ans;
}
int min_swaps_to_make_sequences_increasing(vector<int>v1,vector<int>v2){
    v1.insert(v1.begin(),-1);
    v2.insert(v2.begin(),-1);

    int n=v1.size();
    bool swaped=0;
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return sol(v1,v2,swaped,1,dp);
}

int main() {
    vector<int> v1 = {0,3,5,8,9};
    vector<int> v2 = {2,1,4,6,9};    

    cout << "Minimum Swaps Required: " << min_swaps_to_make_sequences_increasing(v1, v2) << endl;
    return 0;
}