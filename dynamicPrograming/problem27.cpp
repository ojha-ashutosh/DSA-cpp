#include <bits/stdc++.h>
using namespace std;

/*
Problem: Minimum Path Sum (Leetcode 64)
---------------------------------------
Given an `m x n` grid filled with **positive** integers, a robot starts at the 
top-left corner `(0,0)`. The robot can only move **right** or **down** at each 
step. The goal is to reach the **bottom-right** corner `(m-1, n-1)` while 
minimizing the sum of values along the path.

Approach:
- Use **Dynamic Programming (DP) with Memoization**.
- Recursively compute the **minimum path sum** from `(0,0)` to `(m-1,n-1)`, 
  storing results in `dp[i][j]` to avoid recomputation.

Time Complexity: O(m × n)  [Each state is computed once]
Space Complexity: O(m × n)  [For DP table]
*/

class Solution {
public:
    int sol(vector<vector<int>>& v, int m, int n, int i, int j, vector<vector<int>>& dp) {
        if (i >= m || j >= n) return INT_MAX;  // Out of bounds, invalid path
        if (i == m - 1 && j == n - 1) return v[i][j];  // Destination reached

        if (dp[i][j] != -1) return dp[i][j];  // Use stored result

        return dp[i][j] = v[i][j] + min(sol(v, m, n, i + 1, j, dp), sol(v, m, n, i, j + 1, dp));
    }

    int minPathSum(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return sol(v, m, n, 0, 0, dp);
    }
};

// Driver Code
int main() {
    Solution obj;

    // Example input
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout << "Minimum Path Sum: " << obj.minPathSum(grid) << endl;
    return 0;
}
