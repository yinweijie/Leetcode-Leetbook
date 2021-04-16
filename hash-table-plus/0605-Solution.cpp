// 前 K 个高频元素
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x73wrd/

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        // <freq, number>
        using pairII = pair<int, int>;
        priority_queue<pairII, vector<pairII>, greater<pairII>> pq;
        vector<int> res;

        for(auto num : nums) {
            hashMap[num]++;
        }

        for(auto[num, freq] : hashMap) {
            pq.emplace(make_pair(freq, num));
            if(pq.size() > k) {
                pq.pop();
            }
        }

        for(int i = 0; i < k; i++) {
            res.emplace_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};

int main() {
    vector<int> nums {1,1,1,2,2,3};
    int k = 2;
    Solution().topKFrequent(nums, k);
    return 0;
}