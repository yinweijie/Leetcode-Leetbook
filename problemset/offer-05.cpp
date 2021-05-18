// 剑指 Offer 05. 替换空格
// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/

#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(char c : s) {
            if(c == ' ') {
                res += "%20";
            } else {
                res += c;
            }
        }

        return res;
    }
};