#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class knapsack
{
    public:
        int solve_topdown_approch(vector<int>&weight,vector<int>&value,int capacity,vector<vector<int>>&dp,int index){
            if(index==0){
                if(weight[index]<=capacity){
                   return value[index];
                }else{
                    return 0;
                }
            }
            if (dp[index][capacity] != -1) {
                return dp[index][capacity];
            }

            int include=0;
            if(weight[index]<=capacity){
                include=value[index]+solve_topdown_approch(weight,value,capacity-weight[index],dp,index-1);
            }
            int exclude=solve_topdown_approch(weight,value,capacity,dp,index-1);
            dp[index][capacity]=max(include,exclude);
            return dp[index][capacity];
        }
        int solve_bottomdown_approch(vector<int>&weight,vector<int>&value,int capacity,int n){
            vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
            // analyze base case
            // for 0th row
            for(int i=0;i<=capacity;i++){
               if(weight[0]<=i){
                  dp[0][i]=value[0];
               }else{
                  dp[0][i]=0;
               }
            }

            for(int i=1;i<n;i++){
                for(int j=0;j<=capacity;j++){
                    int include=0;
                    if(weight[i]<=j){
                        include=value[i]+dp[i-1][j-weight[i]];
                    }
                    int exclude=0+dp[i-1][j];
                    dp[i][j]=max(include,exclude);
                }
            }
            return dp[n-1][capacity];
        }
        int space_optimization(vector<int>&weight,vector<int>&value,int capacity,int n){
            vector<int>prev(capacity+1,0);
            vector<int>curr(capacity+1,0);

            for(int i=0;i<=capacity;i++){
                if(weight[0]<=i){
                    prev[i]=value[0];
                }else{
                    prev[i]=0;
                }
            }
            for(int i=1;i<n;i++){
                for(int w=0;w<=capacity;w++){
                    int include=0;
                    if(weight[i]<=w){
                        include=value[i]+prev[w-weight[i]];
                    }
                    int exclude=0+prev[w-weight[i]];
                    curr[w]=max(include,exclude);
                }
                prev=curr;
            }
            return prev[capacity];
        }
        int most_optimize(vector<int>&weight,vector<int>&value,int capacity,int n){
            vector<int>curr(capacity+1,0);

            for(int i=0;i<=capacity;i++){
                if(weight[0]<=i){
                    curr[i]=value[0];
                }else{
                    curr[i]=0;
                }
            }
            for(int i=1;i<n;i++){
                for(int w=capacity;w>=0;w--){
                    int include=0;
                    if(weight[i]<=w){
                        include=value[i]+curr[w-weight[i]];
                    }
                    int exclude=0+curr[w-weight[i]];
                    curr[w]=max(include,exclude);
                }
            }
            return curr[capacity];
        }
        int prob(vector<int>weight,vector<int>value,int capacity)
        {
            int n=weight.size();
            vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
            // from last to first element
            // return solve_topdown_approch(weight,value,capacity,dp,n-1);
            // return solve_bottomdown_approch(weight,value,capacity,n);
            // return space_optimization(weight,value,capacity,n);
            return most_optimize(weight,value,capacity,n);
        }
};
int main() {
    vector<int> weight = {1, 2, 3};
    vector<int> value = {10, 15, 40};
    int capacity = 5;

    knapsack ks;
    cout << "Maximum value in knapsack: " << ks.prob(weight, value, capacity) << endl;

    return 0;
}
