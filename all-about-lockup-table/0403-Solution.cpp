// 三数之和
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/xhhlwv/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return vector<vector<int>>();

        sort(nums.begin(), nums.end());

        if(nums[0] > 0) return vector<vector<int>>();
        vector<vector<int>> res;
        for(int k = 0; k <= nums.size() - 3; k++) {
            if(k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }

            int i = k + 1, j = nums.size() - 1;

            while(i < j) {
                int numSum = nums[k] + nums[i] + nums[j];
                if(numSum == 0) {
                    res.emplace_back(vector<int> {nums[k], nums[i], nums[j]});

                    i++;
                    while(nums[i] == nums[i - 1] && i < j) {
                        i++;
                    }
                    if(i == j) {
                        break;
                    }

                    j--;
                    while(nums[j] == nums[j + 1] && i < j) {
                        j--;
                    }
                } else if(numSum > 0) {
                    j--;
                } else {
                    i++;
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums {0,0,0,0};

    Solution().threeSum(nums);

    return 0;
}