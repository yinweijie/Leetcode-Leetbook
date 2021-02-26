// 移动零
// https://leetcode-cn.com/leetbook/read/array-and-string/c6u02/

#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0; // [0, k)为非0元素
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) {
                swap(nums[i], nums[k++]);
            }
        }
    }
};