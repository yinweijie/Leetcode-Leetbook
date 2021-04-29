// 912. 排序数组
// https://leetcode-cn.com/leetbook/read/sort-algorithms/eta44r/

#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

class Solution {
private:
    pair<int, int> partition(vector<int>& nums, int l, int r) {
        int p = rand() % (r - l + 1) + l;
        swap(nums[l], nums[p]);

        // [l + 1 ... lt] < v, [lt + 1 ... i - 1] == v, [gt ... r] > v
        int lt = l, i = l + 1, gt = r + 1;
        while(i < gt) {
            if(nums[i] > nums[l]) {
                gt--;
                swap(nums[i], nums[gt]);
            } else if(nums[i] < nums[l]) {
                lt++;
                swap(nums[i], nums[lt]);
                i++;
            } else {
                i++;
            }
        }

        swap(nums[l], nums[lt]);
        return make_pair(lt, gt);
    }

    void sort(vector<int>& nums, int l, int r) {
        if(l >= r) return;

        auto[lt, gt] = partition(nums, l, r);
        sort(nums, l, lt - 1);
        sort(nums, gt, r);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
};