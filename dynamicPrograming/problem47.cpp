// Longest Common Substring
// Input: s1 = "ABCDGH", s2 = "ACDGHR"
// Output: 4
// Explanation: The longest common substring is "CDGH" with a length of 4.
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int maxLen = 0; // Track longest common substring length

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxLen = max(maxLen, dp[i][j]); // Update max length
                } else {
                    dp[i][j] = 0; // Reset if characters don't match
                }
            }
        }
        return maxLen;
    }
};

int main() {
    string s1 = "abcdef";
    string s2 = "zbcdf";
    Solution ob;
    cout << ob.longestCommonSubstr(s1, s2) << endl;
}
