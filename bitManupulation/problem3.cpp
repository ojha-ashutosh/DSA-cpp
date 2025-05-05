// power of 2 or not

#include <iostream>
using namespace std;

class Solution {
public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (sol.isPowerofTwo(n))
        cout << n << " is a power of 2" << endl;
    else
        cout << n << " is NOT a power of 2" << endl;

    return 0;
}
