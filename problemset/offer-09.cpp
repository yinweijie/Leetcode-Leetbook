// 剑指 Offer 09. 用两个栈实现队列
// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/

#include <stack>

using namespace std;

class CQueue {
private:
    stack<int> stk_in;
    stack<int> stk_out;

    void move() {
        if(stk_in.empty()) return;

        while(!stk_in.empty()) {
            int topE = stk_in.top();
            stk_in.pop();
            stk_out.emplace(topE);
        }
    }

public:
    CQueue() {

    }
    
    void appendTail(int value) {
        stk_in.emplace(value);
    }
    
    int deleteHead() {
        if(stk_out.empty()) {
            move();
        }

        if(stk_out.empty()) return -1;

        int res = stk_out.top();
        stk_out.pop();

        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */