// 寻找旋转排序数组中的最小值
// https://leetcode-cn.com/leetbook/read/binary-search/xeawbd/

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        if(nums[0] <= nums[r]) return nums[0];

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[0] <= nums[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};