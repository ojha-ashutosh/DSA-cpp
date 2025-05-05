
// 1312. Minimum Insertion Steps to Make a String Palindrome
// Example 1:

// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we do not need any insertions.
// Example 2:

// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".

#include <bits/stdc++.h>
using namespace std;

int minInsertions(string s) {
    int n = s.size();
    string s1 = s;
    reverse(s1.begin(), s1.end());

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == s1[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int l = dp[n][n];  // Length of Longest Palindromic Subsequence (LPS)
    // total insertion if total lenghth of string - longest pallendroic
    // subsequence
    return n - l;  
}

int main() {
    string s = "abcaa";  
    // total length=5 longestPalindromeSubseq="aaa"=3
    // ans=5-3=2
    cout << "Minimum Insertions: " << minInsertions(s) << endl;
    return 0;
}
