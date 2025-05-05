// rod cutting 
// Given a rod of length n(size of price) inches and an array of prices, price. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
// Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
// Output: 22
// Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5+17=22

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sol(vector<int> &price, int i, int n, vector<vector<int>>&dp) {
        if (i < 0 || n == 0) return 0;
        if (dp[i][n] != -1) return dp[i][n];

        int exclude = sol(price, i - 1, n, dp);
        int include = (n >= i + 1) ? price[i] + sol(price, i, n - (i + 1), dp) : 0;

        return dp[i][n] = max(exclude, include);
    }

    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return sol(price, n - 1, n, dp);
    }
};

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20}; // Example test case
    Solution ob;
    cout << "Maximum obtainable value: " << ob.cutRod(price) << endl;
    return 0;
}

