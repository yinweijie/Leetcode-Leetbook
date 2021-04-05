// 存在重复元素 III
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/xhw24c/

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> treeSet;

        for(int i = 0; i < nums.size() ; i++) {
            // 在滑动窗口内找满足 num[i] - t <= nums[it] <= nums[i] + t 的数
            auto it = treeSet.lower_bound((long long)nums[i] - t);
            if(it != treeSet.end() && *it <= (long long)nums[i] + t) {
                return true;
            }

            // 如果num[i]在treeSet中有重复，那在上面的判断中，就已经被找到并返回true了
            // 因此不用担心会重复加入同一个数
            treeSet.insert(nums[i]);
            if(treeSet.size() > k) {
                treeSet.erase(nums[i - k]);
            }
        }

        return false;
    }
};