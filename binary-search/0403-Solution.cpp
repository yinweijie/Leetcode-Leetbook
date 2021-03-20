// 寻找峰值
// https://leetcode-cn.com/leetbook/read/binary-search/xem7js/

#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // [l, r]
        int l = 0, r = nums.size() - 1;

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] > nums[mid + 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};