// 最大连续1的个数
// https://leetcode-cn.com/leetbook/read/array-and-string/cd71t/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int slow = 0, fast = 0;
        int res = 0;
        for(; fast <= nums.size(); fast++) {
            if(fast == nums.size() || nums[fast] == 0) {
                res = max(res, fast - slow);
                slow = fast + 1;
            }
        }

        return res;
    }
};