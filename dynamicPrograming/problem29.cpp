// You are given a grid of size n × m, where each cell contains an integer representing the number of chocolates.
// Two players start at the top row, one from the leftmost column (0,0) and the other from the rightmost column (0,m-1).

// Each player can move one step down, with the ability to shift left (-1), right (+1), or stay in place (0).
// The goal is to maximize the sum of chocolates collected while ensuring that both players do not collect the same chocolate twice in one move.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sol(int n, int m, vector<vector<int>> &v, int i, int j1, int j2, vector<vector<vector<int>>> &dp)
    {
        // Boundary Condition: If any index moves out of grid, return a large negative number.
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        {
            return -1e9;
        }

        // Base Case: If we are at the last row
        if (i == n - 1)
        {
            if (j1 == j2)
            {
                return v[i][j1]; // Both reach the same cell
            }
            else
            {
                return v[i][j1] + v[i][j2]; // Different cells
            }
        }

        // Check Memoization Table
        if (dp[i][j1][j2] != -1)
        {
            return dp[i][j1][j2];
        }

        int ans = -1e9;

        // Exploring all 9 possible moves
        for (int k = -1; k <= 1; k++)
        { // Moves for first player
            for (int l = -1; l <= 1; l++)
            { // Moves for second player
                int move1 = j1 + k;
                int move2 = j2 + l;
                int temp;
                if (j1 == j2)
                {
                    temp = v[i][j1]; // Both move to the same cell
                }
                else
                {
                    temp = v[i][j1] + v[i][j2]; // Different cells
                }
                ans = max(ans, temp + sol(n, m, v, i + 1, move1, move2, dp));
            }
        }

        return dp[i][j1][j2] = ans;
    }

    int solve(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return sol(n, m, grid, 0, 0, m - 1, dp);
    }
};

int main()
{
    vector<vector<int>> testCases[] = {
        {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}}, // Test Case 1
        {{4, 2, 3}, {1, 6, 2}, {3, 4, 5}, {2, 3, 1}}  // Test Case 2
    };

    int t = sizeof(testCases) / sizeof(testCases[0]); // Number of test cases

    for (int i = 0; i < t; i++)
    {
        int n = testCases[i].size();
        int m = testCases[i][0].size();
        vector<vector<int>> grid = testCases[i];

        Solution obj;
        cout << "Maximum Chocolates Collected: " << obj.solve(n, m, grid) << "\n";
    }

    return 0;
}
