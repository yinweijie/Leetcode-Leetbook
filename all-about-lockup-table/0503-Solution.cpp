// 字母异位词分组
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/xhofoh/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
        for(const string& str : strs) {
            string strSorted = str;
            sort(strSorted.begin(), strSorted.end());
            hashMap[strSorted].emplace_back(str);
        }

        vector<vector<string>> res;
        for(auto&[strSorted, vecStrs] : hashMap) {
            res.emplace_back(std::move(vecStrs));
        }

        return res;
    }
};