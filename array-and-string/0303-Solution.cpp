// 最长回文子串
// https://leetcode-cn.com/leetbook/read/array-and-string/conm7/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // 状态转移方程：
        // d[i][j] = (s[i] == s[j] && d[i+1][j-1])
        // 边界条件：
        // j - 1 - (i + 1) + 1 <= 1 时，不需要继续递推
        // 即：j - i - 1 <= 1 ==> j - i <= 2 ==> j - i - 1 <= 3
        // 也就是说，i,j之间距离小于等于3的时候，如果s[i] == s[j]，则s(i,j)一定是回文串
        int n = s.length();
        if(n == 0) return string();
        if(n <= 1) return s;
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        int maxLength = 1; // 默认最长子串长度为1
        int begIndex = 0;
        for(int j = 1; j < n; j++) {
            for(int i = 0; i < j; i++) {
                if(s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if(j - i <= 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if(dp[i][j] == true && j - i + 1 > maxLength) {
                    maxLength = j - i + 1;
                    begIndex = i;
                }
            }
        }

        return s.substr(begIndex, maxLength);
    }
};