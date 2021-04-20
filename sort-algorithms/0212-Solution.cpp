// 912. 排序数组
// https://leetcode-cn.com/leetbook/read/sort-algorithms/eunjmt/

#include <vector>
#include <algorithm>

using namespace std;

// 超时
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // int n = nums.size();

        // for(int i = 0; i < n; i++) {
        //     int t = nums[i];

        //     int j = i;
        //     for(j = i; j > 0; j--) {
        //         if(nums[j - 1] > t) {
        //             nums[j] = nums[j - 1];
        //         } else {
        //             break;
        //         }
        //     }

        //     nums[j] = t;
        // }

        return nums;
    }
};