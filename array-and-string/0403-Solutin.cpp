// 数组拆分 I
// https://leetcode-cn.com/leetbook/read/array-and-string/c24he/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // 贪心算法
        // 证明参考：https://leetcode-cn.com/problems/array-partition-i/solution/jue-dui-neng-kan-dong-de-zheng-ming-fan-f7trz/
        sort(nums.begin(), nums.end());

        int res = 0;
        for(int i = 0; i < nums.size(); i += 2) {
            res += nums[i];
        }

        return res;
    }
};