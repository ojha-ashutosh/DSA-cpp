// A parentheses string is valid if and only if:

// It is the empty string,
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

// For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
// Return the minimum number of moves required to make s valid.

 

// Example 1:

// Input: s = "())"
// Output: 1
// Example 2:

// Input: s = "((("
// Output: 3

#include <iostream>
#include <string>
using namespace std;

int minAddToMakeValid(string s) {
    int open = 0, insertions = 0;
    for (char ch : s) {
        if (ch == '(') {
            open++;
        } else { // ch == ')'
            if (open > 0) {
                open--; // match with an open bracket
            } else {
                insertions++; // unmatched closing bracket
            }
        }
    }
    return insertions + open; // unmatched closing + remaining open
}

int main() {
    string s = ")()(";
    cout << "Minimum insertions needed: " << minAddToMakeValid(s) << endl;
    return 0;
}
