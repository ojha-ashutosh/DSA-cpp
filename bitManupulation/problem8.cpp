// Minimum bit flips to convert one no to other
#include <iostream>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        int res = start ^ goal;
        while (res > 0) {
            if (res & 1) {
                ans++;
            }
            res = res >> 1;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    int start = 10;
    int goal = 7;
    
    int result = sol.minBitFlips(start, goal);
    cout << "Minimum bit flips to convert " << start << " to " << goal << " is: " << result << endl;

    return 0;
}
