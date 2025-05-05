// Geek is going for a training program for n days. 
// He can perform any of these activities: Running, Fighting, and Learning Practice.
//  Each activity has some point on each day. As Geek wants to improve all his skills, 
//  he can't do the same activity on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] 
//  represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sol(vector<vector<int>>& arr, int n, int index, int j, vector<vector<int>>& dp) {
        if (index >= n) {
            return 0;
        }
        if (dp[index][j] != -1) {
            return dp[index][j];
        }
        int ans = INT_MIN;
        for (int i = 0; i < 3; i++) {
            if (i != j) {  // Ensuring different activities on consecutive days
                ans = max(ans, arr[index][i] + sol(arr, n, index + 1, i, dp));
            }
        }
        return dp[index][j] = ans;
    }

    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));  // Use (n,4) instead of (n+1,3)
        return sol(arr, n, 0, 3, dp);  // Start with j = 3 (no previous activity)
    }
};
int main() {
    vector<vector<int>> arr = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    };

    Solution obj;
    cout << "Maximum merit points Geek can achieve: " << obj.maximumPoints(arr) << endl;

    return 0;
}
