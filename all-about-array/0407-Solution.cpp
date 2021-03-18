// 盛最多水的容器
// https://leetcode-cn.com/leetbook/read/all-about-array/x96n4v/

#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int i = 0, j = height.size() - 1;

        while(i < j) {
            maxArea = max(maxArea, (j - i) * min(height[i], height[j]));

            if(height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }

        return maxArea;
    }
};