// count no of set bit15

#include <iostream>
using namespace std;

class Solution {
public:
    // Function to count number of 1's in binary representation of n
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            if (n & 1) count++; // check if last bit is 1
            n = n >> 1;         // right shift by 1
        }
        return count;
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    int setBits = sol.countSetBits(n);
    cout << "Number of set bits in " << n << " is: " << setBits << endl;

    return 0;
}
