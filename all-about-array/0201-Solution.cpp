// 移动零
// https://leetcode-cn.com/leetbook/read/all-about-array/x9rh8e/

#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0; // [0, k)

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[k++], nums[i]);
            }
        }
    }
};