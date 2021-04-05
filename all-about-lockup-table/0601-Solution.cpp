// 存在重复元素 II
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/xhn7c6/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;

        for(int i = 0; i < nums.size(); i++) {
            if(hashMap.find(nums[i]) != hashMap.end() && hashMap[nums[i]] >= i - k) {
                return true;
            } else {
                // 对于重复的元素，始终保存最近的那个元素下标，这样被找到的数才会尽可能
                // 落入滑动窗口内
                hashMap[nums[i]] = i;
            }
        }

        return false;
    }
};

int main() {
    vector<int> nums {1,2,2,2,1};
    Solution().containsNearbyDuplicate(nums, 3);
    return 0;
}