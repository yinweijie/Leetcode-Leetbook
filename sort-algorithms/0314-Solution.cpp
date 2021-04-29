// 169. 多数元素
// https://leetcode-cn.com/leetbook/read/sort-algorithms/et2gzs/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};