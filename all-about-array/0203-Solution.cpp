// 移除元素
// https://leetcode-cn.com/leetbook/read/all-about-array/x9p1iv/

#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // [0, k)

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                swap(nums[i], nums[k++]);
            }
        }

        return k;
    }
};