// maximum sum non adjacent element
#include <iostream>
#include <vector>
using namespace std;

int maxSUM_recursively(vector<int> v, int index)
{
    if (index >= v.size())
    {
        return 0;
    }
    int include = v[index] + maxSUM_recursively(v, index + 2);
    int exclude = 0 + maxSUM_recursively(v, index + 1);
    return max(include, exclude);
}
// right to left

int maxSUM_recursively2(vector<int> v, int index)
{
    if (index <0)
    {
        return 0;
    }
    if(index==0){
        return v[0];
    }
    int include = v[index] + maxSUM_recursively2(v, index - 2);
    int exclude = 0 + maxSUM_recursively2(v, index - 1);
    return max(include, exclude);
}
int maxSUM_topdownAproch(vector<int> v, int index, vector<int> &dp)
{
    if (index >= v.size())
    {
        return 0;
    }
    if (dp[index] != -1)
        return dp[index];

    
    int include = v[index] + maxSUM_recursively(v, index + 2);
    int exclude = 0 + maxSUM_recursively(v, index + 1);


    dp[index] = max(include, exclude);
    return dp[index];
}
int maxSUM_bottomUP(vector<int>&v)
{
    int n=v.size();
    vector<int>dp(n,0);
    
    // base case
    dp[0]=v[0];
    dp[1]=max(dp[0],dp[1]);

    for(int i=2;i<n;i++){
        int include=dp[i-2]+v[i];
        int exclude=dp[i-1]+0;
        dp[i]=max(include,exclude);
    }

    return dp[n-1];
    
}
int space_optimization(vector<int>v){
    int n=v.size();

    int prev2=0;
    int prev1=v[0];

    for(int i=1;i<n;i++){
        int include=prev2+v[i];
        int exclude=prev1+0;
        int ans=max(include,exclude);
        prev2=prev1;
        prev1=ans;
    }

    return prev1;
}
int main()
{
    vector<int> v = {9, 9, 8, 2};
    cout << maxSUM_recursively(v, 0) << endl;

    cout << maxSUM_recursively2(v, v.size()-1) << endl;

    // dp
    vector<int> dp(v.size() + 1, -1);
    cout<<maxSUM_topdownAproch(v,0,dp)<<endl;

    cout<<maxSUM_bottomUP(v)<<endl;

    cout<<space_optimization(v);
}