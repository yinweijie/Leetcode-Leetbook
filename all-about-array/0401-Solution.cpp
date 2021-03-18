// 两数之和 II - 输入有序数组
// https://leetcode-cn.com/leetbook/read/all-about-array/x9i1x6/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;

        while(i < j) {
            if(numbers[i] + numbers[j] < target) {
                i++;
            } else if(numbers[i] + numbers[j] > target) {
                j--;
            } else {
                return vector<int> {i + 1, j + 1};
            }
        }

        return vector<int>();
    }
};