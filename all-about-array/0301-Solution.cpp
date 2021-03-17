// 颜色分类
// https://leetcode-cn.com/leetbook/read/all-about-array/x9wv2h/

#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // [0, lt] == 0, [lt + 1, i - 1] == 1, [gt, nums.size() - 1] == 2
        int lt = -1, gt = nums.size(), i = 0;

        while(i < gt) {
            if(nums[i] == 0) {
                lt++;
                swap(nums[lt], nums[i]);
                i++;
            } else if (nums[i] == 2) {
                gt--;
                swap(nums[i], nums[gt]);
            } else {
                i++;
            }
        }
    }
};