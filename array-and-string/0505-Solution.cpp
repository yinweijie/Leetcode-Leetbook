// 寻找旋转排序数组中的最小值
// https://leetcode-cn.com/leetbook/read/array-and-string/c3ki5/

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                return nums[i + 1];
            }
        }

        return nums[0];
    }
};