// Problem: Implement pow(x, n), which calculates x raised to the power n (x^n).
// Here, `x` is a double representing the base, and `n` is an integer representing the exponent.

#include <iostream>
using namespace std;

class Solution {
public:
    double positive(double x, int n) {
        if (n == 0) return 1.0;
        double helf = positive(x, n / 2);
        if (n % 2 == 0) {
            // Even
            return helf * helf;
        } else {
            // Odd n (extra x multiply)
            return x * helf * helf;
        }
    }

    double negative(double x, int n) {
        if (n == -1) return 1 / x;
        double helf = negative(x, n / 2);
        if (n % 2 == 0) {
            return helf * helf;
        } else {
            // Odd n (extra 1/x multiply)
            return (1 / x) * helf * helf;
        }
    }

    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n >= 0) {
            return positive(x, n);
        } else {
            return negative(x, n);
        }
    }
};

// Main function to test the implementation of pow(x, n).
int main() {
    Solution sol;
    double x;
    int n;

    cout << "Enter the base (x): ";
    cin >> x;

    cout << "Enter the exponent (n): ";
    cin >> n;

    double result = sol.myPow(x, n);
    cout << "Result: " << result << endl;

    return 0;
}
