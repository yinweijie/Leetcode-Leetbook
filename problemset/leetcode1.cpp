// 1. 两数之和
// https://leetcode-cn.com/problems/two-sum/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;

        for(int i = 0; i < nums.size(); i++) {
            int rest = target - nums[i];
            if(hashMap.count(rest) > 0) {
                return vector<int> {hashMap[rest], i};
            }

            hashMap[nums[i]] = i;
        }

        return vector<int>();
    }
};