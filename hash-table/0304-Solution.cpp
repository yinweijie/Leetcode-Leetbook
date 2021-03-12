// 只出现一次的数字
// https://leetcode-cn.com/leetbook/read/hash-table/xhsyr2/

#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashSet;

        for(int i = 0; i < nums.size(); i++) {
            if(hashSet.count(nums[i]) == 0) {
                hashSet.insert(nums[i]);
            } else {
                hashSet.erase(nums[i]);
            }
        }

        int res = *find_if(nums.begin(), nums.end(), 
                [&](int i) {
                    return hashSet.count(i) > 0;
                });

        return res;
    }
};