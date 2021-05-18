// 58. 最后一个单词的长度
// https://leetcode-cn.com/problems/length-of-last-word/

#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int r = n - 1;

        while(r >= 0 && s[r] == ' ') {
            r--;
        }

        if(r < 0) return 0;

        int l = r;
        while(true) {
            if(l == 0 || s[l - 1] == ' ') break;

            l--;
        }

        return r - l + 1;
    }
};