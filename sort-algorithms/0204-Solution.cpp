// 283. 移动零
// https://leetcode-cn.com/leetbook/read/sort-algorithms/evfj1d/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] != 0) continue;

            for(int j = i; j + 1 < n; j++) {
                if(nums[j + 1] != 0) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
};