// 912. 排序数组
// https://leetcode-cn.com/leetbook/read/sort-algorithms/ewrwt6/

#include <vector>
#include <algorithm>

using namespace std;

// 超时
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // int i = 0, j = nums.size() - 1;
        // while(i < j) {
        //     int minIndex = i;
        //     int maxIndex = j;

        //     for(int k = i; k <= j; k++) {
        //         if(nums[k] < nums[minIndex]) {
        //             minIndex = k;
        //         }
        //         if(nums[k] > nums[maxIndex]) {
        //             maxIndex = k;
        //         }
        //     }

        //     if(minIndex == maxIndex) break;

        //     swap(nums[i], nums[minIndex]);

        //     if(maxIndex == i) maxIndex = minIndex;

        //     swap(nums[j], nums[maxIndex]);

        //     i++;
        //     j--;
        // }

        return nums;
    }
};

int main() {
    vector<int> arr {5,1,1,2,0,0};
    Solution().sortArray(arr);
    return 0;
}