// 9. 回文数
// https://leetcode-cn.com/problems/palindrome-number/

#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        string str = to_string(x);
        int l = 0, r = str.length() - 1;

        while(l < r) {
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }

        return true;
    }
};