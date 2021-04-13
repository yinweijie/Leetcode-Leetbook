// 至多包含两个不同字符的最长子串
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x7nwq5/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0, r = 0;
        unordered_map<char, int> count;
        int len = 0;

        while(r < s.length()) {
            count[s[r]]++;
            len = r - l + 1;
            r++;

            if(count.size() > 2) {
                count[s[l]]--;
                if(count[s[l]] == 0) {
                    count.erase(s[l]);
                }
                l++;
                len--;
            }
        }

        return len;
    }
};

int main() {
    Solution().lengthOfLongestSubstringTwoDistinct("ccaabbb");
    return 0;
}