// 寻找旋转排序数组中的最小值
// https://leetcode-cn.com/leetbook/read/binary-search/xeu7ie/

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        if(nums[n - 1] > nums[0]) return nums[0];

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] >= nums[0]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};