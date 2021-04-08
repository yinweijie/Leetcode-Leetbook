// 两个数组的交集
// https://leetcode-cn.com/leetbook/read/hash-table-plus/zgccg/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashSet;

        for(int num : nums1) {
            hashSet.emplace(num);
        }

        vector<int> res;
        for(int num : nums2) {
            if(hashSet.count(num) > 0) {
                res.emplace_back(num);
                hashSet.erase(num);
            }
        }

        return res;
    }
};