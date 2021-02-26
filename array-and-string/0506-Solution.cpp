// 删除排序数组中的重复项
// https://leetcode-cn.com/leetbook/read/array-and-string/cq376/

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for(int segStart = 0; segStart < nums.size(); ) {
            int segEnd = segStart;
            while(segEnd < nums.size() && nums[segEnd] == nums[segStart]) {
                segEnd++;
            }
            nums[index++] = nums[segStart];
            segStart = segEnd;
        }
        return index;
    }
};