#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        int n = v.size();
        if (n == 0) return 0;

        int lon = 1;
        unordered_set<int> set;
        
        // Insert all elements into the set
        for (int i = 0; i < n; i++) {
            set.insert(v[i]);
        }

        // Traverse through each element and find the sequence starting point
        for (int ele : set) {
            if (set.find(ele - 1) == set.end()) {  // Check if it's the start of a sequence
                int count = 1;
                int e = ele;
                
                // Count the length of consecutive sequence
                while (set.find(e + 1) != set.end()) {
                    count++;
                    e += 1;
                }
                lon = max(lon, count);  // Update the longest sequence length
            }
        }
        return lon;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Length of the longest consecutive sequence: "
         << sol.longestConsecutive(nums) << endl;
    return 0;
}
