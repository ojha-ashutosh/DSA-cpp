// 🧠 Problem: Check K-th Bit is Set
// You are given:

// An integer n

// A bit position k (0-indexed from the right, i.e., least significant bit is 0th)

// 🔹 Task:
// Write a function to check whether the K-th bit of the binary representation of n is set to 1.



#include<iostream>
using namespace std;


class Solution {
public:
    bool checkKthBit(int n, int k) {
        return (n & (1 << k));
    }
};

int main() {
    Solution sol;
  
    int n, k;

    // Example 1
    n = 5, k = 0;
    cout << "checkKthBit(" << n << ", " << k << ") = " 
         << (sol.checkKthBit(n, k) ? "true" : "false") << endl;

    // Example 2
    n = 5, k = 1;
    cout << "checkKthBit(" << n << ", " << k << ") = " 
         << (sol.checkKthBit(n, k) ? "true" : "false") << endl;

    // Example 3
    n = 8, k = 3;
    cout << "checkKthBit(" << n << ", " << k << ") = " 
         << (sol.checkKthBit(n, k) ? "true" : "false") << endl;

    // Example 4
    n = 10, k = 2;
    cout << "checkKthBit(" << n << ", " << k << ") = " 
         << (sol.checkKthBit(n, k) ? "true" : "false") << endl;

    return 0;
}

