// 125. 验证回文串
// https://leetcode-cn.com/problems/valid-palindrome/

#include <string>

using namespace std;

class Solution {
private:
    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9');
    }

public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while(l < r) {
            while(l < r && !isLetter(s[l])) {
                l++;
            }
            while(l < r && !isLetter(s[r])) {
                r--;
            }

            if(l == r) break;

            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }

        return true;
    }
};