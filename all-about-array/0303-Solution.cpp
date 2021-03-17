// 数组中的第K个最大元素
// https://leetcode-cn.com/leetbook/read/all-about-array/x90rpm/

#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
private:
    int findK(vector<int>& nums, int l, int r, int k) {
        int p = partition(nums, l, r);

        if(p == k) return p;
        if(p > k) return findK(nums, l, p - 1, k);
        return findK(nums, p + 1, r, k);
    }

    int partition(vector<int>& nums, int l, int r) {
        int p = (rand() % (r - l + 1)) + l;
        swap(nums[l], nums[p]);

        // [l + 1, i - 1] <= v, [j + 1, r] >= v
        int i = l + 1, j = r;
        while(true) {
            while(i <= j && nums[i] < nums[l]) {
                i++;
            }
            while(i <= j && nums[j] > nums[l]) {
                j--;
            }

            if(i >= j) {
                break;
            }

            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        swap(nums[l], nums[j]);

        return j;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = findK(nums, 0, nums.size() - 1, nums.size() - k);

        return nums[index];
    }
};

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 1;

    Solution().findKthLargest(nums, k);

    return 0;
}