// 剑指 Offer 40. 最小的 K 个数
// https://leetcode-cn.com/leetbook/read/heap/ev9bph/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> pq;
        vector<int> res;

        if(k == 0) return res;

        for(int num : arr) {
            if(pq.size() >= k) {
                if(num < pq.top()) {
                    pq.emplace(num);
                    pq.pop();
                }
            } else {
                pq.emplace(num);
            }
        }

        for(int i = 0; i < k; i++) {
            res.emplace_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
