// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = INT_MIN;
        int c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                c++;
            }
            if (nums[i] != 1) {
                ans = max(ans, c);
                c = 0;
            }
        }
        return max(ans, c);
    }
};

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1}; // Example input
    Solution sol;
    cout << "The maximum number of consecutive 1s is: " << sol.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
