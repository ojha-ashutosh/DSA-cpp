// cut rod into segment(maximum)
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int cutRODintoSEGMENT_recursivly(int n, int x, int y, int z)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN; // If length becomes negative, invalid case
    }
    int a = cutRODintoSEGMENT_recursivly(n - x, x, y, z) + 1;
    int b = cutRODintoSEGMENT_recursivly(n - y, x, y, z) + 1;
    int c = cutRODintoSEGMENT_recursivly(n - z, x, y, z) + 1;
    return max(a, max(b, c));
}
int cutRODintoSEGMENT_topDOWN(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN; // If length becomes negative, invalid case
    }

    if (dp[n] != -1)
        return dp[n];

    int a = cutRODintoSEGMENT_topDOWN(n - x, x, y, z, dp) + 1;
    int b = cutRODintoSEGMENT_topDOWN(n - y, x, y, z, dp) + 1;
    int c = cutRODintoSEGMENT_topDOWN(n - z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}
int cutRODintoSEGMENT_bottom_up(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i],dp[i - x] + 1);
        if (i - y >= 0)
            dp[i] = max(dp[i],dp[i - y] + 1);
        if (i - z >= 0)
            dp[i] = max(dp[i],dp[i - z] + 1);
    }
    return dp[n];
}

int main()
{
    int n = 7;               // Length of the rod
    int x = 2, y = 3, z = 4; // Possible segment lengths

    int result = cutRODintoSEGMENT_recursivly(n, x, y, z);

    // If result is negative, it means it's not possible to cut the rod
    if (result < 0)
    {
        cout << "It's not possible to cut the rod into given segments." << endl;
    }
    else
    {
        cout << "Maximum number of segments: " << result << endl;
    }

    vector<int> dp(n + 1, -1);
    int ans = cutRODintoSEGMENT_topDOWN(n, x, y, z, dp);
    if (ans < 0)
    {
        cout << "It's not possible to cut the rod into given segments...top-down." << endl;
    }
    else
    {
        cout << "Maximum number of segments: " << result << "  top--down" << endl;
    }

    int ans2 = cutRODintoSEGMENT_bottom_up(n, x, y, z);
    if (ans2 < 0)
    {
        cout << "It's not possible to cut the rod into given segments...bottom-up." << endl;
    }
    else
    {
        cout << "Maximum number of segments: " << result << "  bottom-up" << endl;
    }
    return 0;
}
