// 存在重复元素 III
// https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xpffam/

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> records;

        for(int i = 0; i < nums.size(); i++) {
            // 这里如果用的是lower_bound(records.begin(), records.end(), ...);就会超时
            // 通用版本的算法是线性时间复杂度，set提供的算法是对数时间复杂度
            auto it = records.lower_bound((long long)nums[i] - t);

            if(it != records.end() && *it <= (long long)nums[i] + t) {
                return true;
            }
            
            records.insert(nums[i]);
            if(records.size() == k + 1) {
                records.erase(nums[i - k]);
            }
        }

        return false;
    }
};