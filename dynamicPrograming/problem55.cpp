// 1048. Longest String Chain
// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
// Example 3:

// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }

    bool check(const string &s1, const string &s2) {
        if (s1.size() != s2.size() + 1) return false;
        
        int i = 0, j = 0;
        while (i < s1.size()) {
            if (j < s2.size() && s1[i] == s2[j]) j++;
            i++;
        }
        return j == s2.size();
    }

    int longestStrChain(vector<string>& s) {
        // we need comparater bec we need subset not subsequence
        sort(s.begin(), s.end(), comp);
        int n = s.size();
        vector<int> dp(n, 1);
        int maxi = 1;//we will get minimum 1 word

        for (int curr = 0; curr < n; curr++) {
            for (int prev = 0; prev < curr; prev++) {
                if (check(s[curr], s[prev]) && dp[curr] < dp[prev] + 1) {
                    dp[curr] = dp[prev] + 1;
                }
            }
            maxi = max(maxi, dp[curr]);
        }
        return maxi;
    }
};

int main() {
    Solution sol;
    
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << "Longest String Chain Length: " << sol.longestStrChain(words) << endl;

    return 0;
}
