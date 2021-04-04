// 四数之和
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/xh5n2t/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return vector<vector<int>>();

        sort(nums.begin(), nums.end());

        // 这里不需要这个判断条件，序列可能有小于0的数，nums序列的和有可能是先递减再递增
        // 但是对于三数之和这道题，如果序列第一个数大于0，nums序列的和就是递增的
        // if(nums[0] > target) return vector<vector<int>>();

        vector<vector<int>> res;
        for(int k1 = 0; k1 <= nums.size() - 4; k1++) {
            if(k1 > 0 && nums[k1] == nums[k1 - 1]) continue;

            for(int k2 = k1 + 1; k2 <= nums.size() - 3; k2++) {
                // k2的有效位置判断也需要注意，每次循环的第一个数都是有效的，第一个数以后才需要特判
                if(k2 > k1 + 1 && nums[k2] == nums[k2 - 1]) continue;

                int i = k2 + 1, j = nums.size() - 1;

                while(i < j) {
                    int numSum = nums[k1] + nums[k2] + nums[i] + nums[j];
                    if(numSum == target) {
                        res.emplace_back(vector<int> {nums[k1], nums[k2], nums[i], nums[j]});

                        i++;
                        while(i < j && nums[i] == nums[i - 1]) {
                            i++;
                        }
                        if(i == j) {
                            break;
                        }

                        j--;
                        while(i < j && nums[j] == nums[j + 1]) {
                            j--;
                        }
                    } else if(numSum > target) {
                        j--;
                    } else {
                        i++;
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums {1,-2,-5,-4,-3,3,3,5};
    Solution().fourSum(nums, -11);
    return 0;
}