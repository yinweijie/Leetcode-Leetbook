// 剑指 Offer 67. 把字符串转换成整数
// https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/

#include <string>
#include <climits>

using namespace std;

class Solution {
private:
    bool isNumber(char c) {
        if(c >= '0' && c <= '9') return true;

        return false;
    }
public:
    int strToInt(string str) {
        int start = 0;
        while(start < str.length() && str[start] == ' ') {
            start++;
        }

        // 空字符串
        if(start == str.length()) return 0;
        // 开头为非法字符
        if(!isNumber(str[start]) && str[start] != '-' && str[start] != '+') return 0;

        bool neg = false;
        // 负数
        if(str[start] == '-') {
            neg = true;
            start++;
        } else if(str[start] == '+') {
            neg = false;
            start++;
        } else {
            neg = false;
        }

        int end = start;
        long long num = 0;
        while(end < str.length() && isNumber(str[end])) {
            num = num * 10 + (long long)(str[end] - '0');
            end++;
            if(!neg && num > INT_MAX) return INT_MAX;
            if(neg && -num < INT_MIN) return INT_MIN;
        }

        if(neg) { // 负数
            if(-num < INT_MIN) return INT_MIN;

            return static_cast<int>(-num);
        } else {
            if(num > INT_MAX) return INT_MAX;

            return static_cast<int>(num);
        }
    }
};