// 115. Distinct Subsequences
// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit
// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function with memoization (Top-Down Approach)
    int fn(int i, int j, string &s, string &t, vector<vector<int>>& dp) {
        if (j < 0) return 1; // All characters of t matched
        if (i < 0) return 0; // s is exhausted, but t is not fully matched
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            int include = fn(i - 1, j - 1, s, t, dp); // Match s[i] with t[j]
            int exclude = fn(i - 1, j, s, t, dp);     // Skip s[i] and explore more possibilities
            return dp[i][j] = include + exclude;
        }
        return dp[i][j] = fn(i - 1, j, s, t, dp); // Skip s[i] as it does not match
    }

    // Bottom-Up DP Approach (Tabulation)
    int numDistinctTabulation(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

        // Base case: An empty t is a subsequence of any prefix of s
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        // Base case: A non-empty t cannot be formed from an empty s
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 0;
        }

        // Filling the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[n][m];
    }

    // Wrapper function to choose between Memoization and Tabulation
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fn(n - 1, m - 1, s, t, dp); // Memoization Call
        // return numDistinctTabulation(s, t); // Uncomment for Tabulation
    }
};

int main() {
    Solution sol;
    string s = "rabbbit";
    string t = "rabbit";

    cout << "Number of distinct subsequences (Memoization): " << sol.numDistinct(s, t) << endl;
    cout << "Number of distinct subsequences (Tabulation): " << sol.numDistinctTabulation(s, t) << endl;
    return 0;
}
