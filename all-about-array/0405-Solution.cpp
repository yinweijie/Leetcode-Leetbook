// 反转字符串中的元音字母
// https://leetcode-cn.com/leetbook/read/all-about-array/x93lce/

#include <string>

using namespace std;

class Solution {
private:
    bool isValid(char c) {
        return c == 'a' || c == 'A' ||
               c == 'e' || c == 'E' ||
               c == 'i' || c == 'I' ||
               c == 'o' || c == 'O' ||
               c == 'u' || c == 'U';
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;

        while(i < j) {
            if(!isValid(s[i])) {
                i++;
                continue;
            }
            if(!isValid(s[j])) {
                j--;
                continue;
            }

            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};