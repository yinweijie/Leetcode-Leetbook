// 剑指 Offer 58 - II. 左旋转字符串
// https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        n = n % s.length();
        int start = n;
        int end = s.length() - 1;

        if(n == 0) return s;

        // 保存前面的部分
        string strBack = s.substr(0, n);

        int k = 0;
        // 后面的往前搬运
        for(int i = start; i <= end; i++) {
            s[k] = s[i];
            k++;
        }
        // 前面保存的部分放在末尾
        for(int i = k; i < s.length(); i++) {
            s[i] = strBack[i - k];
        }

        return s;
    }
};