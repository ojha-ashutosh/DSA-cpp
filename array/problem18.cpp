// 4 sum
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && a[i] == a[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && a[j] == a[j - 1]) {
                    continue;
                }
                long long remaining =
                    (long long)target - (long long)a[i] - (long long)a[j];
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    long long sum = (long long)a[left] + (long long)a[right];
                    if (sum == remaining) {
                        ans.push_back({a[i], a[j], a[left], a[right]});
                        while (left < right && a[left] == a[left + 1])
                            left++;
                        while (left < right && a[right] == a[right - 1])
                            right--;
                        left++;
                        right--;
                    } else if (sum < remaining) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    
    // Call the fourSum function
    vector<vector<int>> result = sol.fourSum(nums, target);
    
    // Print the result
    cout << "Quadruples that sum to " << target << ":" << endl;
    for (const auto& quad : result) {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
