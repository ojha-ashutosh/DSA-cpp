// 518. Coin Change II

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.

// Example 1:

// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// Example 2:

// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sol(int amount, vector<int>& coins, int index, int n, vector<vector<int>>& dp) {
        if (amount == 0) return 1;
        if (index >= n || amount < 0) return 0;
        if (dp[index][amount] != -1) return dp[index][amount];

        int take = (amount >= coins[index]) ? sol(amount - coins[index], coins, index, n, dp) : 0;
        int nottake = sol(amount, coins, index + 1, n, dp);

        return dp[index][amount] = take + nottake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return sol(amount, coins, 0, n, dp);
    }
};

int main() {
    vector<int> coins = {1, 2, 5}; // Example coins
    int amount = 5; // Example amount

    Solution ob;
    cout << "Number of ways to make change: " << ob.change(amount, coins) << endl;
    return 0;
}
