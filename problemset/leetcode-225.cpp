// 225. 用队列实现栈
// https://leetcode-cn.com/problems/implement-stack-using-queues/

#include <queue>
#include <algorithm>

using namespace std;

class MyStack {
private:
    queue<int>* q_out;
    queue<int>* q_in;

    void move() {
        while(q_in->size() > 1) {
            int frontE = q_in->front();
            q_out->emplace(frontE);

            q_in->pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyStack() {
        q_out = new queue<int>();
        q_in = new queue<int>();
    }

    ~MyStack() {
        delete q_out;
        delete q_in;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q_in->emplace(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = top();

        q_in->pop();

        swap(q_in, q_out);

        return res;
    }
    
    /** Get the top element. */
    int top() {
        if(q_in->empty()) return -1;

        if(q_in->size() > 1) {
            move();
        }

        int res = q_in->front();

        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (q_in->empty() && q_out->empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */