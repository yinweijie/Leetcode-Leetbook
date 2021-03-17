// 删除排序数组中的重复项
// https://leetcode-cn.com/leetbook/read/all-about-array/x9a60t/

#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0; // [0, k)
        int flagNum = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != flagNum) {
                nums[k++] = nums[i];
                flagNum = nums[i];
            }
        }

        return k;
    }
};