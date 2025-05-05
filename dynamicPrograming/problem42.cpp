// unbounded knapsack

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sol(vector<int>& val, vector<int>& wt, int capacity, vector<vector<int>>& dp, int index) {
        if (index == 0) {
            return (wt[0] <= capacity) ? (capacity / wt[0]) * val[0] : 0;
        }
        
        if (dp[index][capacity] != -1) {
            return dp[index][capacity];
        }

        int exclude = sol(val, wt, capacity, dp, index - 1);
        int include = 0;
        if (wt[index] <= capacity) {
            include = val[index] + sol(val, wt, capacity - wt[index], dp, index);
        }
        
        return dp[index][capacity] = max(include, exclude);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return sol(val, wt, capacity, dp, n - 1);
    }
};

int main() {
    // Hardcoded input values
    vector<int> val = {60, 100, 120};  // Values
    vector<int> wt = {10, 20, 30};     // Weights
    int capacity = 50;                 // Knapsack capacity

    Solution ob;
    cout << ob.knapSack(val, wt, capacity) << endl;

    return 0;
}
