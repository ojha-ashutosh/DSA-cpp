// 152. Maximum Product Subarray
// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int prefix = 1, sufix = 1;

        for (int i = 0; i < n; i++) {
            if (prefix == 0) prefix = 1;
            if (sufix == 0) sufix = 1;

            prefix *= nums[i];
            sufix *= nums[n - i - 1];
            ans = max(ans, max(prefix, sufix));
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, -2, 4}; // Example input
    cout << "Maximum Product Subarray: " << sol.maxProduct(nums) << endl;
    return 0;
}
