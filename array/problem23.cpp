// 455. Assign Cookies
// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size(), m = s.size();
        int i = 0, j = 0, ans = 0;

        while (i < n && j < m) {
            if (s[j] >= g[i]) {  // ✅ Corrected condition
                ans += 1;
                i++;  // Move to next child
            }
            j++;  // Move to next cookie
        }
        return ans;
    }
};

// **Main function with hardcoded input**
int main() {
    vector<int> g = {1, 2, 3};  // Greed factors of children
    vector<int> s = {1, 1};     // Sizes of cookies

    Solution obj;
    int result = obj.findContentChildren(g, s);
    
    cout << "Maximum number of satisfied children: " << result << endl;
    return 0;
}
