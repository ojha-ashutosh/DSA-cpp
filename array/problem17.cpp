// 3 sum 
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin(), v.end()); // Sort the array
        int n = v.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            // Skip duplicates for v[i]
            if (i > 0 && v[i] == v[i - 1]) continue;

            int target = -v[i];
            int left = i + 1, right = n - 1;

            while (right > left) {
                if (v[left] + v[right] == target) {
                    ans.push_back({v[i], v[left], v[right]});

                    // Skip duplicates for v[left]
                    while (left < right && v[left] == v[left + 1]) left++;
                    // Skip duplicates for v[right]
                    while (left < right && v[right] == v[right - 1]) right--;

                    left++;
                    right--;
                } else if (v[left] + v[right] > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test case input
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    // Calling the function
    vector<vector<int>> result = sol.threeSum(nums);

    // Output the results
    cout << "Unique triplets that sum to zero:" << endl;
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
