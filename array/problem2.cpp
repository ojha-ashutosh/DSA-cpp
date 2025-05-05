// Move Zeroes
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // Pointer to place non-zero elements
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (int i = j; i < nums.size(); i++) { // Fill remaining elements with zero
            nums[j++] = 0;
        }
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> nums1 = {0, 1, 0, 3, 12};
    vector<int> nums2 = {0, 0, 1};
    vector<int> nums3 = {1, 2, 3, 0, 0};
    vector<int> nums4 = {0, 0, 0};

    // Test case 1
    cout << "Original: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    sol.moveZeroes(nums1);

    cout << "After Moving Zeroes: ";
    for (int num : nums1) cout << num << " ";
    cout << endl << endl;

    // Test case 2
    cout << "Original: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;

    sol.moveZeroes(nums2);

    cout << "After Moving Zeroes: ";
    for (int num : nums2) cout << num << " ";
    cout << endl << endl;

    // Test case 3
    cout << "Original: ";
    for (int num : nums3) cout << num << " ";
    cout << endl;

    sol.moveZeroes(nums3);

    cout << "After Moving Zeroes: ";
    for (int num : nums3) cout << num << " ";
    cout << endl << endl;

    // Test case 4
    cout << "Original: ";
    for (int num : nums4) cout << num << " ";
    cout << endl;

    sol.moveZeroes(nums4);

    cout << "After Moving Zeroes: ";
    for (int num : nums4) cout << num << " ";
    cout << endl;

    return 0;
}
