/*
    Problem: Single Number (Leetcode 136)
    -------------------------------------
    Given a non-empty array of integers, every element appears twice except for one. 
    Find that single one.

    Note:
    - Your algorithm should have a linear runtime complexity.
    - You must implement it without using extra memory.

    Example:
    Input: [4,1,2,1,2]
    Output: 4
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            a = a ^ nums[i];  // XOR cancels out duplicates
        }
        return a;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,4,4, 1, 2, 1, 2};
    cout << "Single Number: " << sol.singleNumber(nums) << endl;
    return 0;
}
