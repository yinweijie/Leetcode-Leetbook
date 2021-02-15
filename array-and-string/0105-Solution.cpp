// 合并区间
// https://leetcode-cn.com/leetbook/read/array-and-string/c5tv3/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.emplace_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].front() > res.back().back()) {
                res.emplace_back(intervals[i]);
            } else {
                int a = res.back().back();
                int b = intervals[i].back();
                res.back().back() = max(a, b);
            }
        }

        return res;
    }
};