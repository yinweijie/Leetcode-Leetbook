// 三数之和
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/xhhlwv/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> hashMap;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                hashMap[nums[i] + nums[j]] = make_pair(i, j);
            }
        }

        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++) {
            if(hashMap.find(-nums[i]) != hashMap.end()) {
                auto[indexI, indexJ] = hashMap[-nums[i]];

                if(i > indexI && i > indexJ) {
                    res.emplace_back(vector<int> {nums[indexI], nums[indexJ], nums[i]});
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};

    Solution().threeSum(nums);

    return 0;
}