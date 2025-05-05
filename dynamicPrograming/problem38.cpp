// You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.
// Input: nums = [2,-1,0,4,-2,-9]
// Output: 0
// Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
// The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool Is_subset(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (i == 0) return nums[i] == target;

        if (dp[i][target] != -1) return dp[i][target];

        // Exclude current element
        bool exclude = Is_subset(nums, i - 1, target, dp);

        // Include current element if it does not exceed the target
        bool include = false;
        if (nums[i] <= target) {
            include = Is_subset(nums, i - 1, target - nums[i], dp);
        }

        return dp[i][target] = include || exclude;
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        int closest_sum = 0;
        for (int i = target; i >= 0; i--) {
            if (Is_subset(nums, n - 1, i, dp)) {  // ✅ Corrected: Now checking for 'i'
                closest_sum = i;
                break;
            }
        }

        int f_subset = closest_sum;
        int s_subset = total - closest_sum;
        return abs(f_subset - s_subset);
    }
};


// Driver Code
int main() {
    Solution obj;
    vector<int> nums = {3, 9, 7, 3};  // Example input
    cout << "Minimum Subset Sum Difference: " << obj.minimumDifference(nums) << endl;
    return 0;
}
