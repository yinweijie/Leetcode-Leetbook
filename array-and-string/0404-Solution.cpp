// 两数之和 II - 输入有序数组
// https://leetcode-cn.com/leetbook/read/array-and-string/cnkjg/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 证明参考：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/solution/liang-shu-zhi-he-ii-shu-ru-you-xu-shu-zu-by-leet-2/
        int i = 0, j = numbers.size() - 1;
        while(i < j) {
            if(numbers[i] + numbers[j] == target) {
                return vector<int> {i + 1, j + 1};
            }

            if(numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }

        return vector<int>();
    }
};