// 189. Rotate Array

// Hint
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
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
