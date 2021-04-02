// 两个数组的交集
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/f84ft/

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> treeSet;
        for(int num : nums1) {
            treeSet.insert(num);
        }

        vector<int> res;
        for(int num : nums2) {
            if(treeSet.find(num) != treeSet.end()) {
                res.emplace_back(num);
                treeSet.erase(num);
            }
        }

        return res;
    }
};