#include <iostream>
#include <vector>
#include<limits.h>
using namespace std;

class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        int maxSum = INT_MIN;
        for (int i = 1; i < arr.size(); i++) {
            // Calculate sum of adjacent elements
            maxSum = max(maxSum, arr[i] + arr[i - 1]);
        }
        return maxSum;
    }
};

int main() {
    Solution sol; // Create an instance of the Solution class
    
    // Test case
    vector<int> arr = {1, 2, 3, 4, 5};
    
    // Call the function
    int result = sol.pairWithMaxSum(arr);
    
    // Print the result
    cout << "Maximum sum of adjacent pairs: " << result << endl;

    return 0;
}
