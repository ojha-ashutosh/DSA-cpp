// longest odd number
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        for (int i = num.size() - 1; i >= 0; --i) {
            int digit = num[i] - '0';      // Convert char to digit
            if (digit & 1) {               // Check if digit is odd using bitwise AND
                ans = num.substr(0, i + 1); // Return prefix ending at this odd digit
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example test cases
    string num1 = "35427";
    string num2 = "4206";
    string num3 = "1234567890";

    cout << "Input: " << num1 << " → Output: " << sol.largestOddNumber(num1) << endl;
    cout << "Input: " << num2 << " → Output: " << sol.largestOddNumber(num2) << endl;
    cout << "Input: " << num3 << " → Output: " << sol.largestOddNumber(num3) << endl;

    return 0;
}
