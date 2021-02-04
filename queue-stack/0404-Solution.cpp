// 有效的括号
// https://leetcode-cn.com/leetbook/read/queue-stack/g9d0h/

#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                stk.push(c);
            }

            if(c == ')') {
                if(!stk.empty() && stk.top() == '(') {
                    stk.pop();
                } else {
                    return false;
                }
            }
            if(c == ']') {
                if(!stk.empty() && stk.top() == '[') {
                    stk.pop();
                } else {
                    return false;
                }
            }
            if(c == '}') {
                if(!stk.empty() && stk.top() == '{') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};