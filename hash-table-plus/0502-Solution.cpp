// 字母异位词分组
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x7wpt2/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
        vector<vector<string>> res;

        for(const string& str : strs) {
            string strSorted = str;
            sort(strSorted.begin(), strSorted.end());
            hashMap[strSorted].emplace_back(str);
        }

        for(auto&[key, valueVec] : hashMap) {
            res.emplace_back(std::move(valueVec));
        }

        return res;
    }
};