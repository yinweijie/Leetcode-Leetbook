// 两个数组的交集
// https://leetcode-cn.com/leetbook/read/hash-table/xh4sec/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashSet(nums1.begin(), nums1.end());
        unordered_set<int> resSet;
        vector<int> res;

        for(auto num : nums2) {
            if(hashSet.count(num) > 0) {
                resSet.insert(num);
            }
        }

        return vector<int>(resSet.begin(), resSet.end());
    }
};
