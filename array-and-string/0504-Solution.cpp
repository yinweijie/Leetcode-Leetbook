// 反转字符串中的单词 III
// https://leetcode-cn.com/leetbook/read/array-and-string/c8su7/

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        for(int wordBeg = 0; wordBeg < s.length(); wordBeg++) {
            int wordEnd = wordBeg;

            while(wordEnd < s.length() && s[wordEnd] != ' ') {
                wordEnd++;
            }

            reverse(s.begin() + wordBeg, s.begin() + wordEnd);
            wordBeg = wordEnd;
        }

        return s;
    }
};