// 583. Delete Operation for Two Strings
// Example 1:

// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
// Example 2:

// Input: word1 = "leetcode", word2 = "etco"
// Output: 4

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int l = dp[n][m];  // Length of Longest Common Subsequence (LCS)
        return (n - l) + (m - l);  // Minimum deletions required
    }
};

int main() {
    string s1 = "sea";
    string s2 = "eat";
    // explain -> s1 and s2 ->Length of Longest Common Subsequence=2(ea)
    // max delete req = s form 1st and t from 2nd that==2
    // ans= size of 1st-Length of Longest Common Subsequence +size of 2nd-Length of Longest Common Subsequence
    Solution sol;
    cout << "Minimum Deletions: " << sol.minDistance(s1, s2) << endl;
    return 0;
}
