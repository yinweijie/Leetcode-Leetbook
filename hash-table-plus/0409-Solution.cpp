// 最大连续 1 的个数 III
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x72767/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        unordered_map<int, int> count;
        count[0] = 0;
        count[1] = 0;
        int len = 0;

        while(r < nums.size()) {
            count[nums[r]]++;
            len = r - l + 1;
            r++;

            if(count[1] + k < len) {
                count[nums[l]]--;
                l++;
                len--;
            }
        }

        return len;
    }
};