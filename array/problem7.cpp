// 1752. Check if Array Is Sorted and Rotated
 

// Example 1:

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
using namespace std;

class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int n = v.size();
        k = k % n; // To handle cases where k >= n
        vector<int> copy(n);
        for (int i = 0; i < v.size(); i++) {
            copy[i] = v[i]; // Create a copy of the original array
        }

        int j = 0;
        for (int i = n - k; i < n; i++) { // Add the last 'k' elements to the start
            v[j++] = copy[i];
        }
        for (int i = 0; i < n - k; i++) { // Add the remaining elements
            v[j++] = copy[i];
        }

        // Alternatively, reverse-based approach (uncomment below to use):
        // reverse(v.begin(), v.end());
        // reverse(v.begin(), v.begin() + k);
        // reverse(v.begin() + k, v.end());
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7}; // Example input
    int k = 3; // Number of positions to rotate
    Solution sol;
    sol.rotate(nums, k);

    cout << "Array after rotation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
