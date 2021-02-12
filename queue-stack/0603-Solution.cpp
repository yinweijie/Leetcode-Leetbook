// 字符串解码
// https://leetcode-cn.com/leetbook/read/queue-stack/gdwjv/

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res;
        int digit = 0;
        stack<string> stk_str;
        stack<int> stk_num;

        for(char c : s) {
            if(c == '[') {
                stk_str.emplace(res);
                stk_num.emplace(digit);

                res = "";
                digit = 0;
            } else if(c == ']') {
                string pop_str = stk_str.top();
                stk_str.pop();
                int pop_num = stk_num.top();
                stk_num.pop();

                string append_str;
                for(int i = 0; i < pop_num; i++) append_str += res;
                res = pop_str + append_str;
            } else if(c >= '0' && c <= '9') {
                digit = digit * 10 + (c - '0');
            } else { // c == '[a-z]'
                res += c;
            }
        }

        return res;
    }
};