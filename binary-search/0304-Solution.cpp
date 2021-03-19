// 搜索旋转排序数组
// https://leetcode-cn.com/leetbook/read/binary-search/xeog5j/

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] == target) return mid;

            // <= 这里的=不能少了，因为当只有两个元素的时候，mid为0。如果mid为target
            // 所在位置，则上面的if会提前捕捉到，如果mid + 1为target所在位置，则
            // nums[0] <= nums[mid]保证了这种情况进入第一个if分支，并被l = mid + 1;
            // 这个分支捕获到
            if(nums[0] <= nums[mid]) {
                if(nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if(nums[mid] < target && target <= nums[nums.size() - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};