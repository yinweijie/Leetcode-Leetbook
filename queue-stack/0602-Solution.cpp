// 用队列实现栈
// https://leetcode-cn.com/leetbook/read/queue-stack/gw7fg/

#include <queue>
#include <iostream>

using namespace std;

class MyStack {
private:
    queue<int>* q_in;
    queue<int>* q_out;
    int topElement;

    void swap(queue<int>* &q1, queue<int>* &q2) {
        queue<int>* tmp = q1;
        q1 = q2;
        q2 = tmp;
    }

public:
    /** Initialize your data structure here. */
    MyStack() {
        q_in = new queue<int>();
        q_out = new queue<int>();
    }

    ~MyStack() {
        delete q_in;
        delete q_out;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q_in->emplace(x);
        topElement = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = q_in->size() - 1; // 保留最后一个

        for(int i = 0; i < n; i++) {
            q_out->emplace(q_in->front());
            topElement = q_in->front();
            q_in->pop();
        }

        int res = q_in->front();

        q_in->pop();
        swap(q_in, q_out);

        return res;
    }
    
    /** Get the top element. */
    int top() {
        return topElement;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (q_in->size() + q_out->size() == 0);
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
