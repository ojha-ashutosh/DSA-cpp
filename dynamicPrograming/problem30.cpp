// buy and sell 1st

// Problem: Best Time to Buy and Sell Stock (Leetcode 121 - Buy and Sell Stock 1)
// Problem Statement:
// You are given an array prices[], where prices[i] represents the price of a stock on the i-th day.
// You can buy one stock and sell it once to maximize your profit.
// Return the maximum profit you can achieve.

// Rules:

// You must buy before selling (i.e., the buying day index must be before the selling day index).
// If no profit is possible (prices always decrease), return 0.


#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
int max_profit(vector<int>price){
    int mini=price[0];
    int profit=0;
    for(int i=1;i<price.size();i++){
        int diff=price[i]-mini;
        profit=max(diff,profit);
        mini=min(price[i],mini);
    }
    return profit;
}
int main() {
    vector<int> prices = {7, 10, 5, 3, 60, 400};
    cout << "Maximum Profit: " << max_profit(prices) << endl;
    return 0;
}