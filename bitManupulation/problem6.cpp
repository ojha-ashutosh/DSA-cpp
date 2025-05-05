// swap to no
#include <iostream>
#include <utility>  // For make_pair

using namespace std;

class Solution {
public:
    // Function to swap two numbers using bitwise XOR and return them as a pair
    pair<int, int> get(int a, int b) {
        a = a ^ b;  // Step 1: a becomes XOR of a and b
        b = a ^ b;  // Step 2: b becomes the original value of a
        a = a ^ b;  // Step 3: a becomes the original value of b
        
        return make_pair(a, b);  // Return swapped values as pair
    }
};

int main() {
    Solution sol;
    int a, b;

    // Input two numbers to be swapped
    cout << "Enter two numbers to swap: ";
    cin >> a >> b;

    // Get the swapped pair
    pair<int, int> swapped = sol.get(a, b);

    // Output the swapped values
    cout << "After swapping: a = " << swapped.first << ", b = " << swapped.second << endl;

    return 0;
}
