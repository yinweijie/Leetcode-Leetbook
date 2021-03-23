// 两数之和 II - 输入有序数组
// https://leetcode-cn.com/leetbook/read/binary-search/xeqevt/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hashMap;

        for(int i = 0; i < numbers.size(); i++) {
            int rest = target - numbers[i];
            
            if(hashMap.find(rest) != hashMap.end()) {
                return vector<int> {hashMap[rest] + 1, i + 1};
            }

            hashMap[numbers[i]] = i;
        }

        return vector<int>();
    }
};