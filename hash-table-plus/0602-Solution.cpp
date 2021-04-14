// 无重复字符的最长子串
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x7u32t/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashMap;
        int l = 0, r = 0;
        int maxLen = 0;

        while(r < s.length()) {
            char c = s[r];
            r++;
            // 窗口[l, r)内的操作
            hashMap[c]++;

            while(hashMap[c] > 1) {
                hashMap[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r - l);
        }

        return maxLen;
    }
};