// 剑指 Offer 58 - I. 翻转单词顺序
// https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/

#include <string>
#include <cstring>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;

        char* token = strtok((char*)s.data(), " ");
        while(token) {
            stk.emplace(string(token));
            token = strtok(NULL, " ");
        }

        string res;
        while(!stk.empty()) {
            res += stk.top() + " ";
            stk.pop();
        }
        res.pop_back();

        return res;
    }
};