// 寻找旋转排序数组中的最小值 II
// https://leetcode-cn.com/leetbook/read/binary-search/xetw7g/

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

            if(nums[mid] > nums[l]) {
                l = mid + 1;
            } else if(nums[mid] < nums[l]) {
                r = mid;
            } else {

            }
        }

        return nums[l];
    }
};