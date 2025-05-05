// Example 1:

// Input: nums = [2,2,1]
// Output: 1
// Example 2:

// Input: nums = [4,1,2,1,2]
// Output: 4
// Example 1:

// Input: nums = [2,2,1]
// Output: 1
// Example 2:

// Input: nums = [4,1,2,1,2]
// Output: 4
#include <iostream>
#include <vector>
using namespace std;
//xor
//a^a=0
//a^0=a
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            a = a ^ nums[i];
        }
        return a;
    }
};

int main() {
    vector<int> nums = {4, 1, 2, 1, 2}; // Example input
    Solution sol;
    cout << "The single number is: " << sol.singleNumber(nums) << endl;
    return 0;
}
