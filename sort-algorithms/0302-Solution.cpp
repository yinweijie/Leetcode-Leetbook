// 912. 排序数组
// https://leetcode-cn.com/leetbook/read/sort-algorithms/et5ie2/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int h = n / 2;

        while(h >= 1) {
            for(int i = h; i < n; i++) {
                int t = nums[i];
                int j;

                for(j = i; j - h >= 0 && nums[j - h] > t; j -= h) {
                    nums[j] = nums[j - h];
                }

                nums[j] = t;
            }

            h /= 2;
        }

        return nums;
    }
};