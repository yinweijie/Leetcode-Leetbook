// 合并两个有序数组
// https://leetcode-cn.com/leetbook/read/all-about-array/x9lhe7/

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1Copy = nums1;

        int i = 0, j = 0; // i: nums1, j: nums2
        for(int k = 0; k < m + n; k++) {
            if(i >= m) {
                nums1[k] = nums2[j];
                j++;
            } else if(j >= n) {
                nums1[k] = nums1Copy[i];
                i++;
            } else if(nums1Copy[i] < nums2[j]) {
                nums1[k] = nums1Copy[i];
                i++;
            } else {
                nums1[k] = nums2[j];
                j++;
            }
        }
    }
};