#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        int maxele = arr[n - 1];
        ans.push_back(arr[n - 1]); // The last element is always a leader
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= maxele) {
                ans.push_back(arr[i]);
                maxele = arr[i];
            }
        }
        reverse(ans.begin(), ans.end()); // Reverse to maintain order
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> result = sol.leaders(arr);

    cout << "Leaders in the array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
