// 字母异位词分组
// https://leetcode-cn.com/leetbook/read/hash-table/xxo631/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hashMap;

        for(string& str : strs) {
            string strSorted = str;
            sort(strSorted.begin(), strSorted.end());
            hashMap[strSorted].emplace_back(str);
        }

        for(auto it = hashMap.begin(); it != hashMap.end(); it++) {
            res.emplace_back(it->second);
        }

        return res;
    }
};