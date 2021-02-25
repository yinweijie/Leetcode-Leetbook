// 长度最小的子数组
// https://leetcode-cn.com/leetbook/read/array-and-string/c0w4r/

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int res = INT_MAX;
        int start = 0, end = 0;
        for(; end < nums.size(); end++) {
            sum += nums[end];

            while(sum >= target) {
                res = min(res, end - start + 1);
                sum -= nums[start++];
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

int main() {
    vector<int> nums = {1,4,4};
    int target = 4;
    Solution().minSubArrayLen(target, nums);
    return 0;
}