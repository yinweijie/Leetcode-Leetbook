// 存在重复元素
// https://leetcode-cn.com/leetbook/read/hash-table/xhzjp6/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;

        for(auto num : nums) {
            if(hashSet.count(num) == 0) {
                hashSet.insert(num);
            } else {
                return true;
            }
        }

        return false;
    }
};