#include <bits/stdc++.h>
using namespace std;

/*
Problem: Triangle (Leetcode 120)
---------------------------------
Given a triangle array, find the minimum path sum from top to bottom. 
Each step, you may move to adjacent numbers on the row below.

Approach:
- Use **Dynamic Programming (DP) with Memoization**.
- Recursively compute the minimum sum from `(0,0)` to the bottom.
- Store results in `dp[i][j]` to avoid recomputation.

Time Complexity: O(n^2)  [Each subproblem is solved once]
Space Complexity: O(n^2) [For DP table]
*/

class Solution {
public:
    int sol(vector<vector<int>>& v, int i, int j, vector<vector<int>>& dp) {
        int n = v.size(); // Get the triangle size

        if (i == n - 1) {
            return v[i][j]; // Base case: Last row, return value
        }
        if (dp[i][j] != -1) {
            return dp[i][j]; // Return stored result
        }

        // Take the minimum of the two possible paths
        return dp[i][j] = v[i][j] + min(sol(v, i + 1, j, dp), sol(v, i + 1, j + 1, dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // Use `n x n` DP table
        return sol(triangle, 0, 0, dp);
    }
};

// Driver Code (For VS Code)
int main() {
    Solution obj;

    // Example Input: 2D vector (Triangle)
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    // Output the result
    cout << "Minimum Path Sum: " << obj.minimumTotal(triangle) << endl;
    return 0;
}
