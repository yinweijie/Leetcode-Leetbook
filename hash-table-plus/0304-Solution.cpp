// 只出现一次的数字
// https://leetcode-cn.com/leetbook/read/hash-table-plus/zkfje/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashSet;

        for(int num : nums) {
            if(hashSet.count(num) == 0) {
                hashSet.emplace(num);
            } else {
                hashSet.erase(num);
            }
        }

        for(int num : nums) {
            if(hashSet.count(num) > 0) {
                return num;
            }
        }

        return -1;
    }
};