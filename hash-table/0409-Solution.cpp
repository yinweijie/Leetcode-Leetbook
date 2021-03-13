// 存在重复元素 II
// https://leetcode-cn.com/leetbook/read/hash-table/xx5bzh/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;

        for(int i = 0; i < nums.size(); i++) {
            if(hashMap.find(nums[i]) != hashMap.end() && i - hashMap[nums[i]] <= k) {
                return true;
            } else {
                hashMap[nums[i]] = i;
            }
        }

        return false;
    }
};