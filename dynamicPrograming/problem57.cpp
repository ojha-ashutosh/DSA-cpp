// 673. Number of Longest Increasing Subsequence
// Given an integer array nums, return the number of longest increasing subsequences.

// Notice that the sequence has to be strictly increasing.
// Example 1:
// Input: nums = [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
// Example 2:
// Input: nums = [2,2,2,2,2]
// Output: 5
// Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
        int n = v.size();
        int maxi = 1;
        vector<int> dp(n, 1), cnt(n, 1);
        for (int curr = 0; curr < n; curr++) {
            for (int prev = 0; prev < curr; prev++) {
                if (v[curr] > v[prev] && dp[prev] + 1 > dp[curr]) {
                    dp[curr] = dp[prev] + 1;
                    cnt[curr] = cnt[prev];
                } else if (v[curr] > v[prev] && dp[prev] + 1 == dp[curr]) {
                    cnt[curr] += cnt[prev];
                }
            }
            maxi = max(maxi, dp[curr]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi)
                ans += cnt[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 4, 7};
    int result = sol.findNumberOfLIS(nums);
    cout << "Number of Longest Increasing Subsequences: " << result << endl;
    return 0;
}
