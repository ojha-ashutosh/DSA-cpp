// buy and sell 4th
// you and buy and sell multiple time but order will be buy then sell(multiple transistion)
// but you have to pay a transistion fee after every transistion
// u and buy to product continuously
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int sol(int n, vector<int> price, int index, int buy, vector<vector<int>> &dp,int trans_fee)
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
        int buy_kro = -price[index] + sol(n, price, index + 1, 0, dp,trans_fee);
        int skip_kro = 0 + sol(n, price, index + 1, 1, dp,trans_fee);
        profit = max(buy_kro, skip_kro);
    }
    else
    {
        int sell_kro = price[index] -trans_fee+ sol(n, price, index + 1, 1, dp,trans_fee);
        int skip_kro = 0 + sol(n, price, index + 1, 0, dp,trans_fee);
        profit = max(sell_kro, skip_kro);
    }
    return dp[index][buy] = profit;
}
int max_profit(vector<int> price,int trans_fee)
{
    int n = price.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return sol(n, price, 0, 1, dp,trans_fee);
    // 1->buy kr sakte h
    // 0->cant buy
}
int main()
{
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int trans_fee=2;
    cout << "Maximum Profit: " << max_profit(prices,trans_fee) << endl;
    return 0;
}