// 703. 数据流中的第 K 大元素
// https://leetcode-cn.com/leetbook/read/heap/evozem/

#include <vector>
#include <queue>

using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth;

public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;

        for(int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if(pq.size() < kth) {
            pq.emplace(val);
        } else {
            if(val > pq.top()) {
                pq.emplace(val);
                pq.pop();
            }
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */