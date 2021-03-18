// 长度最小的子数组
// https://leetcode-cn.com/leetbook/read/all-about-array/x9gogt/

#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int sum = 0;

        int start = 0, end = 0;
        for(; end < nums.size(); end++) {
            sum += nums[end];

            while(sum >= target) {
                res = min(res, (end - start + 1));
                sum -= nums[start++];
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};