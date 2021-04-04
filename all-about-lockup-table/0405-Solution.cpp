// 四数之和
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/xh5n2t/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        if(nums[0] > target) return vector<vector<int>>();
        if(nums.size() < 4) return vector<vector<int>>();

        for(int k1 = 0; k1 <= nums.size() - 4; k1++) {
            for(int k2 = k1 + 1; k2 <= nums.size() - 3; k2++) {

            }
        }
    }
};