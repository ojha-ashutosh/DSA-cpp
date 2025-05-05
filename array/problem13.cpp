#include <iostream>
#include <vector>
#include <algorithm> // For reverse and swap functions
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        
        // Step 1: Find the first "dip" point from right to left
        // A "dip" point is where nums[i] < nums[i + 1].
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i; // Mark the dip point
                break;
            }
        }
        
        // Step 2: If no "dip" point is found, the array is the largest permutation.
        // Reverse the array to return the smallest permutation.
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Step 3: Find the smallest element larger than nums[idx] to the right of idx
        // This ensures we are finding the next permutation in lexicographical order.
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]); // Swap the elements
                break;
            }
        }
        
        // Step 4: Reverse the elements to the right of idx
        // This ensures the next permutation is in lexicographical order.
        reverse(nums.begin() + idx + 1, nums.end());
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    
    // Create an instance of the Solution class
    Solution sol;
    
    cout << "Original Permutation: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    // Generate the next permutation
    sol.nextPermutation(nums);
    
    cout << "Next Permutation: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}
