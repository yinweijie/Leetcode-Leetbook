// 无重复字符的最长子串
// https://leetcode-cn.com/leetbook/read/hash-table/xxnrdi/

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = -1;
        unordered_set<char> hashSet;
        int res = 0;

        while(r + 1 < s.length()) {
            if(hashSet.find(s[r + 1]) == hashSet.end()) {
                r++;
                hashSet.insert(s[r]);
            } else {
                hashSet.erase(s[l]);
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};