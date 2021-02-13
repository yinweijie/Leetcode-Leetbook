// 寻找数组的中心索引
// https://leetcode-cn.com/leetbook/read/array-and-string/yf47s/

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumAll = accumulate(nums.begin(), nums.end(), 0);

        int sumPre = 0;
        for(int i = 0; i < nums.size(); i++) {
            // sumPre == sumAll - sumPre - nums[i]
            if(sumPre * 2 == sumAll - nums[i]) {
                return i;
            }

            sumPre += nums[i];
        }

        return -1;
    }
};
