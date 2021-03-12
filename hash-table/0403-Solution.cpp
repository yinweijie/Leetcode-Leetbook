// 两数之和
// https://leetcode-cn.com/leetbook/read/hash-table/xhb0fv/

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;

        for(int i = 0; i < nums.size(); i++) {
            int rest = target - nums[i];
            if(hashMap.count(rest) > 0 && hashMap[rest] != i) {
                return vector<int>{hashMap[rest], i};
            }

            hashMap[nums[i]] = i;
        }

        return vector<int>();
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;

    Solution().twoSum(nums, target);

    return 0;
}