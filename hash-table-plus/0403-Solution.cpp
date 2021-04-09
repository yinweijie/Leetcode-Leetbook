// 两数之和
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x7ejcs/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;

        for(int i = 0; i < nums.size(); i++) {
            if(hashMap.count(target - nums[i]) > 0) {
                return vector<int> {hashMap[target - nums[i]], i};
            }

            hashMap[nums[i]] = i;
        }

        return vector<int>();
    }
};