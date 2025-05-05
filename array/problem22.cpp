// 54. Spiral Matrix
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int left = 0, right = m - 1, top = 0, bottom = n - 1;
        vector<int> ans;

        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int i = left; i <= right; i++) {
                ans.push_back(arr[top][i]);
            }
            top++;
            
            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(arr[i][right]);
            }
            right--;
            
            if (top <= bottom) {
                // Traverse from right to left
                for (int i = right; i >= left; i--) {
                    ans.push_back(arr[bottom][i]);
                }
                bottom--;
            }
            
            if (left <= right) {
                // Traverse from bottom to top
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(arr[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

int main() {
    // Input matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Create Solution object
    Solution sol;
    vector<int> result = sol.spiralOrder(matrix);
    
    // Print result
    cout << "Spiral order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
