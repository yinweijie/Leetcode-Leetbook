// 数据流中的移动平均值
// https://leetcode-cn.com/leetbook/read/queue-stack/k1msc/

#include <vector>
#include <queue>

using namespace std;

class MovingAverage {
private:
    queue<int> q;
    int sz, sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = size;
        sum = 0;
    }
    
    double next(int val) {
        if(q.size() == sz) {
            sum -= q.front();
            q.pop();
        }

        q.push(val);
        sum += val;

        return static_cast<double>(sum) / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */