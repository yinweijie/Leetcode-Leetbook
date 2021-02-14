// 搜索插入位置
// https://leetcode-cn.com/leetbook/read/array-and-string/cxqdh/

#include <vector>

using namespace std;

class Solution {
public:
    // 采用lower_ceil的模版，即>=target的最小值
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
};