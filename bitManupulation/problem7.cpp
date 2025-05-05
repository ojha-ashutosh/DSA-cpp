// division by bit (leet code me tle)
#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MAX && divisor == 1) return INT_MAX;
        if (dividend == divisor) return 1;

        bool sign = true;
        if (dividend >= 0 && divisor < 0) sign = false;
        if (dividend <= 0 && divisor > 0) sign = false;

        long n = abs(dividend);
        long d = abs(divisor);
        long ans = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            ans += (1 << cnt);
            n -= (d << cnt);
        }

        if (ans == (1 << 31) && sign == true) {
            return INT_MAX;
        }
        if (ans == (1 << 31) && sign == false) {
            return INT_MIN;
        }

        return sign ? ans : -ans;
    }
};

int main() {
    Solution solution;
    int dividend = 10;
    int divisor = 3;

    int result = solution.divide(dividend, divisor);
    cout << "Result: " << result << endl;

    dividend = 17;
    divisor = -3;

    result = solution.divide(dividend, divisor);
    cout << "Result: " << result << endl;

    return 0;
}
