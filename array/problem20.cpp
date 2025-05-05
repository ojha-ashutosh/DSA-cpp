// 229. Majority Element II
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        int count1 = 0, count2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;

        // Step 1: Find potential candidates
        for (int i = 0; i < n; i++) {
            if (count1 == 0 && arr[i] != ele2) {
                count1++;
                ele1 = arr[i];
            } else if (count2 == 0 && arr[i] != ele1) {
                count2++;
                ele2 = arr[i];
            } else if (arr[i] == ele1)
                count1++;
            else if (arr[i] == ele2)
                count2++;
            else {
                count1--;
                count2--;
            }
        }

        // Step 2: Validate candidates
        int mini = n / 3;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == ele1) c1++;
            if (arr[i] == ele2) c2++;
        }

        // Step 3: Collect results
        vector<int> a;
        if (c1 > mini) a.push_back(ele1);
        if (c2 > mini) a.push_back(ele2);

        return a;
    }
};

int main() {
    Solution sol; // Create an instance of the Solution class.

    // Predefined input array
    vector<int> nums = {3, 2, 3};

    // Call the majorityElement function
    vector<int> result = sol.majorityElement(nums);

    // Output the result
    cout << "Majority elements: ";
    if (result.empty()) {
        cout << "None";
    } else {
        for (int x : result) {
            cout << x << " ";
        }
    }
    cout << endl;

    return 0;
}
