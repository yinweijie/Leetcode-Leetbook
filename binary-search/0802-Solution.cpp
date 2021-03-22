// 寻找旋转排序数组中的最小值 II
// https://leetcode-cn.com/leetbook/read/binary-search/xetw7g/

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        if(nums[n - 1] > nums[0]) return nums[0];
        
        // 注意：这里只能用mid和r进行比较判断，如果用mid和l比较
        // 会出问题，比如：[4,5,6,1,2,3]
        // 第一轮：mid: 6; l: 4; r: 3，此时在左半边有序数组
        // 第二轮：如果利用nums[mid] > nums[l]的判断准则去判断，会得到l: 1; mid: 2; r: 3
        // 此时也满足nums[mid] > nums[l]但是却在右半边数组

        // 但是用mid和r比较就不会有问题，当nums[mid] < nums[r]的时候，此时mid只可能在
        // 右半边数组，不可能在左半边数组，例如上面的数组[4,5,6,1,2,3]，假设会出现某种
        // 情况下有：l: 4; mid: 5; r: 6，这种情况要出现，说明上一步有r = mid;发生，而
        // 要出现这种情况，在上一步必须满足nums[mid] < nums[r];即上一步6右侧的数(nums[r])比
        // 6大，如果此时6离最小值很近了，这种那6一定是大于nums[r]的，即使6后面还有很多
        // 大于6的数，那就可以继续用上面的方法递推，最终在左侧有序数组中找到一个离最小值
        // 很近的点，最后回归到nums[r] > 这个数，不成立的情况。
        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] > nums[r]) {
                l = mid + 1;
            } else if(nums[mid] < nums[r]) {
                r = mid;
            } else {
                r--;
            }
        }

        return nums[l];
    }
};

int main() {
    vector<int> arr {10,1,10,10,10};
    Solution().findMin(arr);
    return 0;
}