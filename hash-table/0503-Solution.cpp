// 移位字符串分组
// https://leetcode-cn.com/leetbook/read/hash-table/xxr887/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    string shift(string& key) {
        int dist = key[0] - 'a';
        for(int i = 0; i < key.length(); i++) {
            key[i] = (key[i] - dist < 'a') ? ('z' - (dist - (key[i] - 'a') - 1)) : (key[i] - dist);
        }

        return key;
    }

public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hashMap;

        for(auto& str : strings) {
            string key = str;
            hashMap[shift(key)].emplace_back(str);
        }

        for(auto it = hashMap.begin(); it != hashMap.end(); ++it) {
            res.emplace_back(it->second);
        }

        return res;
    }
};