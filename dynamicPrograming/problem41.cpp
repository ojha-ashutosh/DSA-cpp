// 494. Target Sum

// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

 

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3


// convert this in same two subset format
// s1-s2=target
// so new target=total-old target divide by 2
// ans =total subset with given target

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sol(vector<int>& arr, int n, int i, int target, vector<vector<int>>& dp) {
        if (i == n) {
            return (target == 0) ? 1 : 0;
        }
        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        int exclude = sol(arr, n, i + 1, target, dp);
        int include = (target >= arr[i]) ? sol(arr, n, i + 1, target - arr[i], dp) : 0;

        return dp[i][target] = exclude + include;
    }

    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();
        int total = accumulate(arr.begin(), arr.end(), 0); // Calculate sum of array

        if (total - target < 0 || (total - target) % 2 != 0) {
            return 0;
        }

        target = (total - target) / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return sol(arr, n, 0, target, dp);
    }
};

// **Main function with hardcoded input**
int main() {
    vector<int> arr = {1, 1, 1, 1, 1};  // Example input array
    int target = 3;  // Target sum difference

    Solution obj;
    int result = obj.findTargetSumWays(arr, target);
    
    cout << "Number of ways to achieve target sum: " << result << endl;
    return 0;
}
