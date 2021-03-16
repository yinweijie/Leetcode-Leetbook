// 前 K 个高频元素
// https://leetcode-cn.com/leetbook/read/hash-table/xxwb2v/

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for(int num : nums) {
            hashMap[num]++;
        }

        // pair<frequency, number>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto[num, freq] : hashMap) {
            if(pq.size() < k) {
                pq.emplace(make_pair(freq, num));
            } else {
                if(pq.top().first < freq) {
                    pq.pop();
                    pq.emplace(make_pair(freq, num));
                }
            }
        }

        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.emplace_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};