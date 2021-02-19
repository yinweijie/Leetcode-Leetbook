// 实现 strStr()
// https://leetcode-cn.com/leetbook/read/array-and-string/cm5e2/

#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();

        if(needle.length() == 0) {
            return 0;
        }

        for(int i = 0; i + (n - 1) < haystack.length(); i++) {
            const string& s = haystack.substr(i, n);
            if(s == needle) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    string haystack = "a";
    string needle = "a";

    Solution().strStr(haystack, needle);
    return 0;
}