// 215. 数组中的第 K 个最大元素
// https://leetcode-cn.com/leetbook/read/sort-algorithms/osxtdc/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < k; i++) {
            int maxIndex = i;
            for(int j = i; j < n; j++) {
                if(nums[j] > nums[maxIndex]) {
                    maxIndex = j;
                }
            }

            swap(nums[i], nums[maxIndex]);
        }

        return nums[k - 1];
    }
};