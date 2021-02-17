// 翻转字符串里的单词
// https://leetcode-cn.com/leetbook/read/array-and-string/crmp5/

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return s;

        reverse(s.begin(), s.end());

        int index = 0;
        for(int wordBeg = 0; wordBeg < s.length(); wordBeg++) {
            if(s[wordBeg] != ' ') {
                if(index > 0) {
                    s[index++] = ' ';
                }

                int wordEnd = wordBeg;
                while(wordEnd < s.length() && s[wordEnd] != ' ') {
                    s[index++] = s[wordEnd++];
                }

                reverse(s.begin() + index - (wordEnd - wordBeg), s.begin() + index);

                wordBeg = wordEnd;
            }
        }

        s.erase(s.begin() + index, s.end());
        return s;
    }
};

int main() {
    string s = "the sky is blue";

    Solution().reverseWords(s);

    return 0;
}