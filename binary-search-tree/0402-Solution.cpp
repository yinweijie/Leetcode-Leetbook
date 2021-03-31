// 数据流中的第K大元素
// https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xpjovh/

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

        if(nums.size() == 0) return;

        for(int num : nums) {
            pq.emplace(num);
            if(pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.emplace(val);
        if(pq.size() > kth) {
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
