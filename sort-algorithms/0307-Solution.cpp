// 215. 数组中的第 K 个最大元素
// https://leetcode-cn.com/leetbook/read/sort-algorithms/osen2g/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto num : nums) {
            pq.emplace(num);

            if(pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};