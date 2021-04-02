// 有效的字母异位词
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/f4o67/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashMap;

        for(char c : s) {
            hashMap[c]++;
        }

        for(char c : t) {
            if(hashMap.find(c) != hashMap.end()) {
                hashMap[c]--;

                if(hashMap[c] == 0) {
                    hashMap.erase(c);
                }
            } else {
                return false;
            }
        }

        return hashMap.size() == 0;
    }
};