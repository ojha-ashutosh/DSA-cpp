/*
    🧠 Problem: Count Number of Set Bits in a Number
    ------------------------------------------------
    Given an integer n, count how many bits are set (i.e., how many 1's)
    are present in the binary representation of n.

    Example:
    Input:  5      → Binary: 101  → Output: 2
    Input:  7      → Binary: 111  → Output: 3
    Input:  15     → Binary: 1111 → Output: 4
    Input:  10     → Binary: 1010 → Output: 2
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Function to count number of 1's in binary representation of n
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            if (n & 1) count++;
            n = n >> 1;
        }
        return count;
    }
};

int main() {
    Solution sol;
    int nums[4];

    cout << "Enter 4 numbers:\n";
    for (int i = 0; i < 4; i++) {
        cin >> nums[i];
    }

    cout << "\nSet bits count for each:\n";
    for (int i = 0; i < 4; i++) {
        int result = sol.countSetBits(nums[i]);
        cout << "Number: " << nums[i] << " → Set Bits: " << result << endl;
    }

    return 0;
}
