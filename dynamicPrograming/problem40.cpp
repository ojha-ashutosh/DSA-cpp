// Partitions with Given Difference

// Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 
// Input: arr[] =  [5, 2, 6, 4], d = 3
// Output: 1
// Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.

// here we have to find two subset with diff d
// s1-s2=d
// s1=total -s2
// s2=total-d divid by(target)
// so now wwe have to find total subset with sum == target



#include <bits/stdc++.h>
using namespace std;




class Solution {
  public:
    int sol(vector<int>& arr,int n,int i, int target,vector<vector<int>>&dp){
        if (i == n) {
            return (target == 0) ? 1 : 0;
        }
        if(dp[i][target]!=-1)
        {
            return dp[i][target];
        }
        
        int exclude = sol(arr, n, i + 1, target, dp);
        int include = (target >= arr[i]) ? sol(arr, n, i + 1, target - arr[i], dp) : 0;
        return dp[i][target] = exclude + include;
    }
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += arr[i];
        }
        if(total-d<0 || (total-d)%2!=0){
            return 0;
            // it cant be less then 0 all positive no
            // it should be even bec it is divided by 2 and if odd it will be in point
        }
        int target=(total-d)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return sol(arr,n,0,target,dp);
    }
};


//{ Driver Code Starts.

int main() {
    vector<int> arr = {1, 1, 2, 3}; // Example input array
    int d = 1; // Example target difference

    Solution ob;
    int ans = ob.countPartitions(arr, d);
    
    cout << "Number of partitions with difference " << d << ": " << ans << endl;

    return 0;
}
// } Driver Code Ends