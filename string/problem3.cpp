// 1021. Remove Outermost Parentheses
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int c = 0;
        for (auto i : s) {
            if (i == '(') {
                if (c > 0) res += '(';
                c++;
            } else if (i == ')') {
                c--;
                if (c > 0) res += ')';
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Sample inputs
    string input1 = "(()())(())";
    string input2 = "(()())(())(()(()))";
    string input3 = "()()";

    cout << "Input: " << input1 << endl;
    cout << "Output: " << sol.removeOuterParentheses(input1) << endl;

    cout << "Input: " << input2 << endl;
    cout << "Output: " << sol.removeOuterParentheses(input2) << endl;

    cout << "Input: " << input3 << endl;
    cout << "Output: " << sol.removeOuterParentheses(input3) << endl;

    return 0;
}
