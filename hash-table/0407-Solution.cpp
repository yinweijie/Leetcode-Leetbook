// 字符串中的第一个唯一字符
// https://leetcode-cn.com/leetbook/read/hash-table/xxx94s/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashMap;

        for(int i = 0; i < s.length(); i++) {
            hashMap[s[i]]++;
        }

        for(int i = 0; i < s.length(); i++) {
            if(hashMap[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};