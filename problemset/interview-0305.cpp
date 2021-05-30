// 面试题 03.05. 栈排序
// https://leetcode-cn.com/problems/sort-of-stacks-lcci/

#include <stack>

using namespace std;

class SortedStack {
private:
    stack<int> stk1;
    stack<int> stk2;

private:
    void moveStk1ToStk2() {
        int topE = stk1.top();
        stk1.pop();
        stk2.emplace(topE);
    }

public:
    SortedStack() {

    }
    
    void push(int val) {
        while(!stk1.empty() && val > stk1.top()) {
            moveStk1ToStk2();
        }
    }
    
    void pop() {

    }
    
    int peek() {

    }
    
    bool isEmpty() {

    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */