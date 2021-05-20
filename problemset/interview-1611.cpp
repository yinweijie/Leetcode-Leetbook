// 面试题 16.11. 跳水板
// https://leetcode-cn.com/problems/diving-board-lcci/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k == 0) return vector<int>();

        unordered_set<int> hashSet;
        vector<int> res;
        res.reserve(k + 1); // [0, k]

        for(int cnt = 0; cnt <= k; cnt++) {
            int totalLength = cnt * longer + (k - cnt) * shorter;

            if(hashSet.count(totalLength) > 0) continue;

            res.emplace_back(totalLength);
            hashSet.insert(totalLength);
        }

        return res;
    }
};