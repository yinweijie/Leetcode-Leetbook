// 两个数组的交集 II
// https://leetcode-cn.com/leetbook/read/hash-table/xx5hsd/

#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums1.size(); i++) {
            hashMap[nums1[i]]++;
        }

        vector<int> res;
        for(int i = 0; i < nums2.size(); i++) {
            if(hashMap.count(nums2[i]) > 0) {
                res.emplace_back(nums2[i]);
                hashMap[nums2[i]]--;

                if(hashMap[nums2[i]] == 0) {
                    hashMap.erase(nums2[i]);
                }
            }
        }

        return res;
    }
};