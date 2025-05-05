#include <bits/stdc++.h>
using namespace std;
vector<int> largestDivisibleSubset(vector<int>& v) {
    int n = v.size();
    sort(v.begin(), v.end());
    vector<int> dp(n, 1), parant(n);
    int maxi = 0, last_index = 0;
    for (int curr = 0; curr <n; curr++) {
        parant[curr] = curr;
        for(int prev=0;prev<curr;prev++)
        {
            if(v[curr] % v[prev] == 0 && dp[curr]<dp[prev]+1)
            {
                dp[curr]=dp[prev]+1;
                parant[curr]=prev;
            }
        }
        if(maxi<dp[curr])
        {
            maxi=dp[curr];
            last_index=curr;
        }
    }
    vector<int> ans;
    while (last_index >=0 ) {  
        ans.push_back(v[last_index]);
        if (parant[last_index] == last_index) break;  // Avoid infinite loop
        last_index = parant[last_index];
    }

    reverse(ans.begin(), ans.end());  // Fix: Reverse to maintain order
    return ans;
}
int main() {
    vector<int> arr = {1, 2, 4, 8, 16};  // Input array

    vector<int> res = largestDivisibleSubset(arr);
    
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}