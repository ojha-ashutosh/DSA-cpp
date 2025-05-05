// Problem: Minimum Cost for Ticket 
// You are given a list of days when a traveler plans to travel. The traveler can purchase one of three types of travel passes:

// A 1-day pass that covers a single day at a cost of cost[0].
// A 7-day pass that covers any 7 consecutive days at a cost of cost[1].
// A 30-day pass that covers any 30 consecutive days at a cost of cost[2].
// Write a function to calculate the minimum cost to cover all the travel days by selecting the appropriate passes. You can buy multiple passes, but only one pass at a time.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int MIN_COST(int n,vector<int>&cost,vector<int>&days,int index,vector<int>&dp){
    if(index>=n){
        return 0;
    }
    if(dp[index]!=-1) return dp[index];
    // option 1 ->pass of 1 day
    int option1=cost[0]+MIN_COST(n,cost,days,index+1,dp);

    // option 2->7 day pass
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);

    int option2=cost[1]+MIN_COST(n,cost,days,i,dp);
    
    // option 3->30 day pass
    for(i=index;i<n && days[i]<days[index]+30;i++);

    int option3=cost[2]+MIN_COST(n,cost,days,i,dp);

    dp[index]=min(option1,min(option2,option3));
    return dp[index];

}
int main()
{
    int n = 7; // Number of days the traveler wants to travel
    vector<int> cost = {2,7,20}; // Cost for 1-day, 7-day, and 30-day passes
    vector<int> days = {1,3,4,5,7,8,10}; // The days on which travel is planned
    
    // DP table initialized to -1
    vector<int> dp(n+1, -1);
    
    // Output the minimum cost to cover all the days
    cout << MIN_COST(n, cost, days, 0, dp) << endl;
    
    return 0;
}