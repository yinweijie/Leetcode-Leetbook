// 最小栈
// https://leetcode-cn.com/leetbook/read/queue-stack/g5l7d/

#include <vector>
#include <climits>

using namespace std;

class MinStack {
private:
    vector<int> data;
    vector<int> min_data;
public:
    /** initialize your data structure here. */
    MinStack() {
        min_data.emplace_back(INT_MAX);
    }
    
    void push(int x) {
        data.emplace_back(x);
        min_data.emplace_back(min(x, min_data.back()));
    }
    
    void pop() {
        data.pop_back();
        min_data.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return min_data.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */