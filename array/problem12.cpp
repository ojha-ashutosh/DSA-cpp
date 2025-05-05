#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Function for positive numbers only
    int lenOfLongestSubarr_onlyPositive(vector<int>& arr, int k) {
        int i = 0, j = 0;
        int maxlen = 0, sum = 0;
        int n = arr.size();
        while (i < n) {
            sum += arr[i];
            while (sum > k && j <= i) {
                sum -= arr[j];
                j++;
            }
            if (sum == k) {
                maxlen = max(maxlen, i - j + 1);
            }
            i++;
        }
        return maxlen;
    }

    // Function for both positive and negative numbers
    int lenOfLongestSubarr_allPositiveNegative(vector<int>& arr, int k) {
        int n = arr.size();
        int maxlen = 0;
        int sum = 0;
        unordered_map<int, int> prevsum;  // To store prefix sums
        prevsum[0] = -1;  // For cases where the sum equals k from the start
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            int remaining = sum - k;
            if (prevsum.find(remaining) != prevsum.end()) {
                maxlen = max(maxlen, i - prevsum[remaining]);
            }
            if (prevsum.find(sum) == prevsum.end()) {  // Store the first occurrence
                prevsum[sum] = i;
            }
        }
        return maxlen;
    }
};

int main() {
    Solution sol;

    // Test with positive numbers only
    vector<int> arr1 = {10, 5, 2, 7, 1, 9};
    int k1 = 15;
    cout << "Length of longest subarray with sum " << k1 << " (positive only): "
         << sol.lenOfLongestSubarr_onlyPositive(arr1, k1) << endl;

    // Test with both positive and negative numbers
    vector<int> arr2 = {10, -1, 2, 7, -3, 1, 9};
    int k2 = 15;
    cout << "Length of longest subarray with sum " << k2 << " (positive and negative): "
         << sol.lenOfLongestSubarr_allPositiveNegative(arr2, k2) << endl;

    return 0;
}

