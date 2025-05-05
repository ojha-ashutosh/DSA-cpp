// buy and sell 3rd

// you and buy and sell multiple time but order will be buy then sell
// u and buy to product continuously
// maximum transistion alow =limit...say limit =2
// 1 transistion = buy plus sell
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int sol(int n, vector<int> &price, int index, int buy,int limit, vector<vector<vector<int>>>&dp)
{
    if (index >= n)
    {
        return 0;
    }
    if(limit==0){
        return 0;
    }
    int profit = 0;
    if (dp[index][buy][limit] != -1)
    {
        return dp[index][buy][limit];
    }
    if (buy)
    {
        int buy_kro = -price[index] + sol(n, price, index + 1, 0, limit,dp);
        int skip_kro = 0 + sol(n, price, index + 1, 1,limit, dp);
        profit = max(buy_kro, skip_kro);
    }
    else
    {
        int sell_kro = price[index] + sol(n, price, index + 1, 1,limit-1, dp);
        int skip_kro = 0 + sol(n, price, index + 1, 0,limit, dp);
        profit = max(sell_kro, skip_kro);
    }
    return dp[index][buy][limit] = profit;
}
int max_profit(vector<int> price,int limit)
{
    int n = price.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(limit+1,-1)));
    return sol(n, price, 0, 1,limit, dp);
    // 1->buy kr sakte h
    // 0->cant buy
}
int main()
{
    vector<int> prices = {3, 2, 6, 5, 0, 7};
    int limit =2;
    cout << "Maximum Profit: " << max_profit(prices,limit) << endl;
    return 0;
}