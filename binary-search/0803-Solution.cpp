// 两个数组的交集
// https://leetcode-cn.com/leetbook/read/binary-search/xe820v/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashSet;
        for(auto num : nums1) {
            hashSet.insert(num);
        }

        unordered_set<int> resSet;
        for(auto num : nums2) {
            if(hashSet.find(num) != hashSet.end()) {
                resSet.insert(num);
            }
        }

        return vector<int>(resSet.begin(), resSet.end());
    }
};