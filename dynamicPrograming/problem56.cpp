#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int LongestBitonicSequence(vector<int> &v) {
        int n = v.size();
        if (n == 0) return 0;  

        vector<int> dp(n, 1);   // LIS from left
        vector<int> dp1(n, 1);  // LDS from right

        // Compute LIS (Left to Right)
        for (int curr = 0; curr < n; curr++) {
            for (int prev = 0; prev < curr; prev++) {
                if (v[prev] < v[curr] && dp[prev] + 1 > dp[curr]) {
                    dp[curr] = dp[prev] + 1;
                }
            }
        }

        // Compute LDS (Right to Left)
        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = n - 1; prev > curr; prev--) {
                if (v[prev] > v[curr] && dp1[prev] + 1 > dp1[curr]) {  
                    dp1[curr] = dp1[prev] + 1;
                }
            }
        }

        // Compute the maximum bitonic subsequence length
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > 1 && dp1[i] > 1) {  
                maxi = max(maxi, dp[i] + dp1[i] - 1);
            }
        }

        return maxi;
    }
};

// **Main function with predefined input**
int main() {
    vector<int> nums = {5, 7, 9};  // 🔥 Hardcoded input

    Solution obj;
    int res = obj.LongestBitonicSequence(nums);
    
    cout << "Longest Bitonic Subsequence Length: " << res << endl;

    return 0;
}
