// 最长公共前缀
// https://leetcode-cn.com/leetbook/read/array-and-string/ceda1/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;

        if(strs.size() == 0) return res;
        if(strs.size() == 1) return strs[0];

        for(int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++) {
                if(i == strs[j].length() || strs[j][i] != c) {
                    return res;
                } else {
                    if(j == strs.size() - 1) {
                        res += strs[0][i];
                    }
                }
            }
        }

        return res;
    }
};