// total subset
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sol(vector<int>& arr, int n, int i, int target, vector<vector<int>>& dp) {
        // if (target == 0) {  
        //     return 1;  
        // }
        // if (i >= n) {       we cant use this for eg if input is like (2,3,4,0,0,1) target is 7
                              //  so tatal ans =3 but as it get target 0 it will not move furthur so dont cout lot of sub set  
        //     return 0;  
        // }

        if(i==n){
            return (target==0)?1:0;
        }
        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        int exclude = sol(arr, n, i + 1, target, dp);
        int include = (target >= arr[i]) ? sol(arr, n, i + 1, target - arr[i], dp) : 0;
        
        return dp[i][target] = exclude + include;
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return sol(arr, n, 0, target, dp);
    }
};

int main() {
    int n = 6, target = 10;  // Hardcoded values

    vector<int> arr = {5, 2, 3, 10, 6, 8};  // Hardcoded array

    Solution solution;
    cout << solution.perfectSum(arr, target) << endl;  // Print result

    return 0;
}
