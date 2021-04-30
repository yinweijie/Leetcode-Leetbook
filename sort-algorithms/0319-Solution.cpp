// 剑指 Offer 51. 数组中的逆序对
// https://leetcode-cn.com/leetbook/read/sort-algorithms/etdd3m/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    void mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r) return;

        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    void merge(vector<int>& nums, int l, int mid, int r) {
        int n = r - l + 1;
        int i = l, j = mid + 1;
        vector<int> tmp(n);
        std::copy(nums.begin() + l, nums.begin() + l + n, tmp.begin());

        for(int k = 0; k < n; k++) {
            if(i >= mid + 1) {
                nums[k + l] = tmp[j - l];
                j++;
            } else if(j >= r + 1) {
                nums[k + l] = tmp[i - l];
                i++;
            } else {
                if(tmp[i - l] > tmp[j - l]) {
                    nums[k + l] = tmp[j - l];
                    j++;

                    res += (mid - i + 1);
                } else {
                    nums[k + l] = tmp[i - l];
                    i++;
                }
            }
        }
    }

    int res = 0;

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return res;
    }
};

int main() {
    vector<int> nums {4, 3, 2, 1};
    int res = Solution().reversePairs(nums);
    for(auto num : nums) {
        cout << num << endl;
    }
    cout << endl;
    cout << res << endl;
    return 0;
}