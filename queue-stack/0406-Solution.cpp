// 逆波兰表达式求值
// https://leetcode-cn.com/leetbook/read/queue-stack/gomvm/

#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
private:
    bool isOperator(const string& e) {
        return (e == "+" || e == "-" || e == "*" || e == "/");
    }

    int operate(int left, int right, const string& oper) {
        if(oper == "+") return left + right;
        if(oper == "-") return left - right;
        if(oper == "*") return left * right;
        if(oper == "/") return left / right;

        return 0;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        int res = 0;

        for(const string& e : tokens) {
            if(isOperator(e)) {
                int numRight = atoi(stk.top().c_str());
                stk.pop();
                int numLeft = atoi(stk.top().c_str());
                stk.pop();

                res = operate(numLeft, numRight, e);
                stk.emplace(to_string(res));
            } else {
                stk.emplace(e);
            }
        }

        return atoi(stk.top().c_str());
    }
};