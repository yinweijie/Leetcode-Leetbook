// 验证回文串
// https://leetcode-cn.com/leetbook/read/all-about-array/x9tqjc/

#include <string>
#include <cctype>

using namespace std;

class Solution {
private:
    bool isValid(char c) {
        return (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9');
    }
public:
    bool isPalindrome(string s) {
        if(s.length() == 0) return true;

        int i = 0, j = s.length() - 1;

        while(i < j) {
            char ci = tolower(s[i]);
            char cj = tolower(s[j]);
            if(!isValid(ci)) {
                i++;
                continue;
            }
            if(!isValid(cj)) {
                j--;
                continue;
            }

            if(ci != cj) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};

int main() {
    Solution().isPalindrome("0P");
    return 0;
}