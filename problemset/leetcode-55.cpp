// 55. 跳跃游戏
// https://leetcode-cn.com/problems/jump-game/

#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        assert(nums.size() > 0);

        int maxPos = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(i > maxPos) return false;

            maxPos = max(i + nums[i], maxPos);
        }

        return true;
    }
};