// 存在重复元素 II
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x7m3zm/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hashSet;

        for(int i = 0; i < nums.size(); i++) {
            if(hashSet.count(nums[i]) > 0) {
                return true;
            }

            // 这里要放在后面的if语句之前，如果先删除，再添加，对于k为0的情况
            // 本应保证滑动窗口里始终没有元素，但第0个元素却会被添加进来
            hashSet.emplace(nums[i]);

            if(hashSet.size() > k) {
                hashSet.erase(nums[i - k]);
            }
        }

        return false;
    }
};