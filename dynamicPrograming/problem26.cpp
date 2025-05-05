#include <bits/stdc++.h>
using namespace std;

/*
Problem: Unique Paths II (Leetcode 63)
---------------------------------------
A robot is placed on an `m x n` grid at the top-left corner `(0,0)`. It can 
only move **right** or **down**. However, some cells contain obstacles (marked as `1`), 
which the robot cannot pass through. Find the total number of unique paths 
to reach the bottom-right corner `(m-1, n-1)`.

Constraints:
- The robot starts at `(0,0)`.
- The robot can only move **right** or **down**.
- The grid has obstacles (1 represents an obstacle, 0 represents a free space).

Approach:
- **Dynamic Programming (DP) with Memoization**:
  - Use a 2D DP table `dp[i][j]` where each cell stores the number of unique 
    paths from `(i, j)` to `(m-1, n-1)`.
  - If the robot reaches an **obstacle (`1`)**, return `0` since it cannot pass.
  - Recursively calculate the number of paths from `(i, j)` by summing:
    1. Paths from `(i+1, j)` (moving down)
    2. Paths from `(i, j+1)` (moving right)

Time Complexity: **O(m × n)** (Each state is computed once)
Space Complexity: **O(m × n)** (For DP table)
*/

class Solution {
public:
    int sol(vector<vector<int>>& v, int m, int n, int i, int j, vector<vector<int>>& dp) {
        if (i >= m || j >= n || v[i][j] == 1) return 0;  // Out of bounds or obstacle
        if (i == m - 1 && j == n - 1) return 1;  // Reached destination
        if (dp[i][j] != -1) return dp[i][j];  // Use stored result

        return dp[i][j] = sol(v, m, n, i + 1, j, dp) + sol(v, m, n, i, j + 1, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m = o.size();
        int n = o[0].size();
        if (o[0][0] == 1 || o[m - 1][n - 1] == 1) return 0;  // Start or end blocked

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return sol(o, m, n, 0, 0, dp);
    }
};

// Driver Code
int main() {
    Solution obj;
    
    vector<vector<int>> obstacleGrid1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    vector<vector<int>> obstacleGrid2 = {
        {0, 1},
        {0, 0}
    };

    cout << "Unique Paths with Obstacles (3x3): " << obj.uniquePathsWithObstacles(obstacleGrid1) << endl;
    cout << "Unique Paths with Obstacles (2x2): " << obj.uniquePathsWithObstacles(obstacleGrid2) << endl;

    return 0;
}
