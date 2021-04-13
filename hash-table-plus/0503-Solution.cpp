// 移位字符串分组
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x7deic/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    string shift(string str) {
        int baseShift = str[0] - 'a';
        if(baseShift == 0) return str;

        for(int i = 0; i < str.size(); i++) {
            int rest = str[i] - baseShift - 'a';
            if(rest < 0) {
                str[i] = 'z' + rest + 1;
            } else {
                str[i] = str[i] - baseShift;
            }
        }

        return str;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hashMap;
        vector<vector<string>> res;

        for(const string& str : strings) {
            string strShifted = shift(str);
            hashMap[strShifted].emplace_back(str);
        }

        for(auto&[key, vecStrs] : hashMap) {
            res.emplace_back(vecStrs);
        }

        return res;
    }
};

int main() {
    vector<string> strings {"az", "ba"};
    Solution().groupStrings(strings);
    return 0;
}