// 347. 前 K 个高频元素
// https://leetcode-cn.com/leetbook/read/heap/evr651/

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        // pair<freq, num>
        using pair_ii = pair<int, int>;
        priority_queue<pair_ii, vector<pair_ii>, greater<pair_ii>> pq;
        vector<int> res;

        for(int num : nums) {
            hashMap[num]++;
        }

        for(auto[num, freq] : hashMap) {
            if(pq.size() < k) {
                pq.emplace(make_pair(freq, num));
            } else {
                if(freq > pq.top().first) {
                    pq.emplace(make_pair(freq, num));
                    pq.pop();
                }
            }
        }

        for(int i = 0; i < k; i++) {
            res.emplace_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};