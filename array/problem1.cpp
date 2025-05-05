//  Check if Array Is Sorted and Rotated
// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

// Example 2:

// Input: nums = [2,1,3,4]
// Output: false
// Explanation: There is no sorted array once rotated that can make nums.
// Example 3:

// Input: nums = [1,2,3]
// Output: true
// Explanation: [1,2,3] is the original sorted array.
// You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool check(vector<int>& v) {
        if (is_sorted(v.begin(), v.end())) {
            return true;
        }
        int n = v.size();
        int idx;
        for (int i = 0; i < n - 1; i++) { // Fixed loop to avoid out-of-bounds
            if (v[i] > v[i + 1]) {
                idx = i + 1;
                break;
            }
        }
        bool a = is_sorted(v.begin(), v.begin() + idx);
        bool b = is_sorted(v.begin() + idx, v.end());
        if (a && b && v[n - 1] <= v[0]) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> nums1 = {3, 4, 5, 1, 2};
    vector<int> nums2 = {2, 1, 3, 4};
    vector<int> nums3 = {1, 2, 3, 4, 5}; // Already sorted
    vector<int> nums4 = {5, 1, 2, 3, 4}; // Rotated at the end

    // Output results
    cout << boolalpha; // Print booleans as true/false
    cout << "Test case 1: " << sol.check(nums1) << endl; // true
    cout << "Test case 2: " << sol.check(nums2) << endl; // false
    cout << "Test case 3: " << sol.check(nums3) << endl; // true
    cout << "Test case 4: " << sol.check(nums4) << endl; // true

    return 0;
}
