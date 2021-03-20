// 找到 K 个最接近的元素
// https://leetcode-cn.com/leetbook/read/binary-search/xeve4m/

#include <vector>

using namespace std;

class Solution {
private:
    // >= x的最小索引
    int findPivotLarger(vector<int>& nums, int x) {
        int l = 0, r = nums.size();

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] < x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }

    // <= x的最大索引
    int findPivotSmaller(vector<int>& nums, int x) {
        int l = -1, r = nums.size() - 1;

        while(l < r) {
            int mid = l + (r - l + 1) / 2;

            if(nums[mid] > x) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }

        return l;
    }

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pivotIndexLarger = findPivotLarger(arr, x);
        int pivotIndexSmaller = findPivotSmaller(arr, x);
        int pivotIndex = (pivotIndexLarger - x) > (x - pivotIndexSmaller) ? 
                pivotIndexSmaller : pivotIndexLarger;

        if(pivotIndex == 0) {
            return vector<int>(arr.begin(), arr.begin() + k);
        }

        if(pivotIndex == arr.size()) {
            return vector<int>(arr.end() - k, arr.end());
        }

        int leftCount = 0, rightCount = 0;
        if((k - 1) % 2 == 0) {
            leftCount = rightCount = (k - 1) / 2;
        } else {
            leftCount = (k - 1) / 2 + 1;
            rightCount = (k - 1) / 2;
        }

        int leftIndex = pivotIndex - leftCount;
        int rightIndex = pivotIndex + rightCount;

        if(leftIndex < 0) {
            rightIndex += (-leftIndex);
            leftIndex = 0;
        }
        if(rightIndex >= arr.size()) {
            leftIndex -= (rightIndex - (arr.size() - 1));
            rightIndex = arr.size() - 1;
        }

        return vector<int>(arr.begin() + leftIndex, arr.begin() + rightIndex + 1);
    }
};

int main() {
    vector<int> arr {0,1,1,1,2,3,6,7,8,9};
    Solution().findClosestElements(arr, 9, 4);
    return 0;
}