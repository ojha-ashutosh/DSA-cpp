// // buy and sell 2nd
// you and buy and sell multiple time but order will be buy then sell
// u and buy to product continuously
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int sol(int n, vector<int> price, int index, int buy, vector<vector<int>> &dp)
{
    if (index >= n)
    {
        return 0;
    }
    int profit = 0;
    if (dp[index][buy] != -1)
    {
        return dp[index][buy];
    }
    if (buy)
    {
        int buy_kro = -price[index] + sol(n, price, index + 1, 0, dp);
        int skip_kro = 0 + sol(n, price, index + 1, 1, dp);
        profit = max(buy_kro, skip_kro);
    }
    else
    {
        int sell_kro = price[index] + sol(n, price, index + 1, 1, dp);
        int skip_kro = 0 + sol(n, price, index + 1, 0, dp);
        profit = max(sell_kro, skip_kro);
    }
    return dp[index][buy] = profit;
}
int max_profit(vector<int> price)
{
    int n = price.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return sol(n, price, 0, 1, dp);
    // 1->buy kr sakte h
    // 0->cant buy
}
int main()
{
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout << "Maximum Profit: " << max_profit(prices) << endl;
    return 0;
}