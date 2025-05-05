#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& v) {
        vector<int> dp(n, 1), parant(n, -1);
        int maxi = 1, last_index = 0;

        // Compute LIS using DP
        for (int curr = 1; curr < n; curr++) {  
            for (int prev = 0; prev < curr; prev++) {  
                if (v[curr] > v[prev] && dp[curr] < dp[prev] + 1) {
                    dp[curr] = dp[prev] + 1;
                    parant[curr] = prev;  
                }
            }
            if (dp[curr] > maxi) {
                maxi = dp[curr];
                last_index = curr;
            }
        }

        // Backtrack to construct LIS
        vector<int> ans;
        for (int i = last_index; i != -1; i = parant[i]) {  
            ans.push_back(v[i]);
        }

        reverse(ans.begin(), ans.end());  
        return ans;
    }
};
int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    Solution s;
    vector<int>ans;
    ans=s.longestIncreasingSubsequence(nums.size(),nums);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}
