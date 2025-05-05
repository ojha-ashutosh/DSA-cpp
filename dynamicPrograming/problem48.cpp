
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void longestPalindromeSubseq(string s1) {
            int n = s1.size();
            int m = n;
            string s2 = s1;
            reverse(s2.begin(), s2.end());
    
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
            for (int i = 0; i <= n; i++) {
                dp[i][0] = 0;
            }
            for (int j = 0; j <= m; j++) {
                dp[0][j] = 0;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (s1[i - 1] == s2[j - 1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    } else {
                        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                    }
                }
            }
            int l= dp[n][m];
            string ans(l,' ');
            int idx=l-1;
            int i=n;int j=m;
            while(i>0 && j>0){
                if(s1[i-1]==s2[j-1]){
                    ans[idx]=s1[i-1];
                    idx--;
                    i--;
                    j--;
                }else if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }else
                {
                    j--;
                }
            }
            cout<<ans;
        }
};
int main() {
    Solution ob;
    ob.longestPalindromeSubseq("cbbbbdbbbbdc");
}
