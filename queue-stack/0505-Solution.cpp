// 目标和
// https://leetcode-cn.com/leetbook/read/queue-stack/ga4o2/

#include <vector>

using namespace std;

class Solution {
private:
    int count = 0;

    void calSum(vector<int>& nums, int S, int sum, int i) {
        if(i == nums.size()) {
            if(sum == S) {
                count++;
            }
            return;
        }

        calSum(nums, S, sum - nums[i], i + 1);
        calSum(nums, S, sum + nums[i], i + 1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        calSum(nums, S, 0, 0);

        return count;
    }
};