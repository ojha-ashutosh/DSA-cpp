// minimum sideway jump
// 3 lone and we have to reach the last position ans these lone have obstracles
// u cant move to obstracles but u can jump it side wise
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int sol(vector<int> &obstracles, int current_position, int currenet_lane, vector<vector<int>> &dp)
{
    int n = obstracles.size();
    if (current_position == n - 1)
    {
        return 0;
    }
    if (dp[current_position][currenet_lane] != -1)
    {
        return dp[current_position][currenet_lane];
    }
    if (obstracles[current_position + 1] != currenet_lane)
    {
        return sol(obstracles, current_position + 1, currenet_lane, dp);
    }

    int ans = INT_MAX;
    // there are more then one way to move so we have to take minimum 
    for (int i = 1; i <= 3; i++)
    {
        if (i != currenet_lane && obstracles[current_position] != i)
        {
            ans = min(ans, 1 + sol(obstracles, current_position, i, dp));
            //plus 1 for 1 sideways movement 
        }
    }

    dp[current_position][currenet_lane] = ans;
    return dp[current_position][currenet_lane];
}
int min_side_jump(vector<int> &obstracles)
{
    int n = obstracles.size();
    vector<vector<int>> dp(n, vector<int>(4 + 1, -1));
    return sol(obstracles, 0, 2, dp);
}
int main() {
    vector<int> obstacles = {0, 1, 2, 3, 0}; // Example input
    cout << "Minimum Side Jumps: " << min_side_jump(obstacles) << endl;
    return 0;
}