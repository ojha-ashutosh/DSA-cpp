/*
    Problem: Generate All Subsets (Power Set) Using Bit Manipulation
    -----------------------------------------------------------------
    Given a set represented as a vector of distinct integers, generate all possible subsets.

    Approach:
    - For a set of size n, there are 2^n subsets.
    - Use integers from 0 to 2^n - 1 to represent the inclusion/exclusion of elements.
    - If the j-th bit of the number is set, include the j-th element in the subset.

    Example:
    Input: [1, 2, 3]
    Output: [], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;  // 2^n subsets
        vector<vector<int>> result;

        for (int i = 0; i < total; i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j))//set bit
                {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3,4};
    vector<vector<int>> res = sol.subsets(nums);

    cout << "Subsets:\n";
    for (auto subset : res) {
        cout << "[";
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
