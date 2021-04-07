// 215. 数组中的第 K 个最大元素
// https://leetcode-cn.com/leetbook/read/heap/eve1o3/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num : nums) {
            if(pq.size() < k) {
                pq.emplace(num);
            } else {
                if(num > pq.top()) {
                    pq.emplace(num);
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};