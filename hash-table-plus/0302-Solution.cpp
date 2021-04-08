// 存在重复元素
// https://leetcode-cn.com/leetbook/read/hash-table-plus/zk5fi/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;

        for(int num : nums) {
            if(hashSet.count(num) > 0) {
                return true;
            }
            hashSet.emplace(num);
        }

        return false;
    }
};