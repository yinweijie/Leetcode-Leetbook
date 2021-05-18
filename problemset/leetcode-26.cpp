// 26. 删除有序数组中的重复项
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int flag = INT_MIN;
        int k = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != flag) {
                nums[k++] = nums[i];
                flag = nums[i];
            }
        }

        return k;
    }
};