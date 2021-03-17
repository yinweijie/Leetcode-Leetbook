// 删除排序数组中的重复项 II
// https://leetcode-cn.com/leetbook/read/all-about-array/x9nivs/

#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0; // [0, k)
        int flagNum = INT_MAX;
        int count = 0;

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != flagNum) {
                flagNum = nums[i];
                nums[k++] = nums[i];
                count = 1;
            } else {
                if(count < 2) {
                    nums[k++] = nums[i];
                    count++;
                }
            }
        }

        return k;
    }
};