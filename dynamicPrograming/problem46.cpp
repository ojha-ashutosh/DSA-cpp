#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

string longest_common_subsequence(string t1, string t2) {
    int n = t1.size(), m = t2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Filling the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (t1[i - 1] == t2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstructing the LCS string
    int l = dp[n][m];
    string a(l, ' '); // Initialize string with correct size
    int index = l - 1;
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (t1[i - 1] == t2[j - 1]) {
            a[index] = t1[i - 1];
            index--;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return a;
}

// Driver code for testing
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << "LCS: " << longest_common_subsequence(s1, s2) << endl;
    return 0;
}
