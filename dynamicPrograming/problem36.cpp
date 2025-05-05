// Problem Statement: Edit Distance
// Given two strings A and B, return the minimum number of operations required to convert string A into string B.

// The allowed operations are:

// Insertion: Insert a character into A.
// Deletion: Remove a character from A.
// Replacement: Replace a character in A with another character.

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int sol(string a, string b, int n, int m, int i, int j, vector<vector<int>> &dp)
{
    if (i >= n)
    {
        return m - j;
    }
    if (j >= m)
    {
        return n - i;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 0;
    if (a[i] == b[j])
    {
        ans = sol(a, b, n, m, i + 1, j + 1, dp);
    }
    else
    {
        // insertion
        int insert = 1 + sol(a, b, n, m, i, j + 1, dp);
        // deletion
        int deletion = 1 + sol(a, b, n, m, i + 1, j, dp);
        // reverse
        int replace = 1 + sol(a, b, n, m, i + 1, j + 1, dp);

        ans = min(insert, min(deletion, replace));
    }

    return dp[i][j] = ans;
}
int edit_distance(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return sol(a, b, n, m, 0, 0, dp);
}
int main()
{
    string a1 = "horse", b1 = "ros";
    string a2 = "intention", b2 = "execution";

    cout << "Edit Distance (horse -> ros): " << edit_distance(a1, b1) << endl;
    cout << "Edit Distance (intention -> execution): " << edit_distance(a2, b2) << endl;

    return 0;
}
