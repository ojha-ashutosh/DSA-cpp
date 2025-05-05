// 26. Remove Duplicates from Sorted Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size();
        int i = 1;
        int j = 0;
        while (i < n) {
            if (v[i] == v[j]) {
                i++;
            } else {
                j++;
                v[j] = v[i];
                i++;
            }
        }
        return j + 1;
    }
};

int main() {
    vector<int> v = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    Solution sol;
    int newSize = sol.removeDuplicates(v);
    for (int i = 0; i < newSize; i++) {
        cout << v[i] << " ";
    }
    return 0;
}
