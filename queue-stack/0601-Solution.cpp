// 用栈实现队列
// https://leetcode-cn.com/leetbook/read/queue-stack/gvtxe/

#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stk_in;
    stack<int> stk_out;

    void move() {
        if(stk_out.empty()) {
            while(!stk_in.empty()) {
                stk_out.emplace(stk_in.top());
                stk_in.pop();
            }
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk_in.emplace(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        move();

        int res = stk_out.top();
        stk_out.pop();

        return res;
    }
    
    /** Get the front element. */
    int peek() {
        move();

        return stk_out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (stk_out.size() + stk_in.size() == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */