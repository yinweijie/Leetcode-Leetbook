// 在排序数组中查找元素的第一个和最后一个位置
// https://leetcode-cn.com/leetbook/read/binary-search/xenp13/

#include <vector>

using namespace std;

class Solution {
private:
    // >= target最小索引
    int findLeft(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }

    // > target最小索引
    int findRight(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = findLeft(nums, target);
        if(leftIndex >= nums.size() || nums[leftIndex] != target) {
            return vector<int> {-1, -1};
        }

        int rightIndex = findRight(nums, target);
        return vector<int> {leftIndex, rightIndex - 1};
    }
};