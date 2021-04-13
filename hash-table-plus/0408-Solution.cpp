// 替换后的最长重复字符
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x7auk1/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        unordered_map<char, int> count;
        int maxCount = 0;
        int len = 0;
        int maxLen = 0;

        while(r < s.length()) {
            count[s[r]]++;
            maxCount = max(maxCount, count[s[r]]);
            len = r - l + 1;
            maxLen = len;
            r++;

            // 不满足条件时，l只用向左移一位，因为假如上一步满足条件最长的maxLen为4
            // 这一步先会试探5是否满足，如果不满足，则l向右一位，maxLen又变为4，没必要继续
            // 向右，继续向右只会找到小于4的结果
            if(maxCount + k < len) {
                count[s[l]]--;
                l++;
                maxLen--;
                maxCount = max(maxCount, count[s[l]]);
            }
        }

        return maxLen;
    }
};

int main() {
    Solution().characterReplacement("ABAA", 0);
    return 0;
}