// 912. 排序数组
// https://leetcode-cn.com/leetbook/read/sort-algorithms/o1s7mc/

#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for(auto num : nums) {
            if(num < minNum) minNum = num;
            if(num > maxNum) maxNum = num;
        }

        // [minNum, maxNum] ==> [0, maxNum - minNum]
        int n = maxNum - minNum + 1;
        vector<int> cnt(n);
        for(auto num : nums) {
            cnt[num - minNum]++;
        }

        // 修改cnt的含义为，i前面共有cnt[i]个元素
        int preCount = 0;
        for(int i = 0; i < n; i++) {
            preCount += cnt[i];
            cnt[i] = preCount - cnt[i];
        }

        vector<int> res(nums.size());
        for(auto num : nums) {
            int index = cnt[num - minNum]; // num前面有cnt[num - minNum]个数
            res[index] = num; // 这个数正好是num对应的index值
            cnt[num- minNum]++; // num已经插入了一次，cnt对应值要增加
        }

        return res;
    }
};