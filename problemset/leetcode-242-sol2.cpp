// 242. 有效的字母异位词
// https://leetcode-cn.com/problems/valid-anagram/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> hashMap;

        for(char c : s) {
            hashMap[c]++;
        }

        for(char c : t) {
            if(hashMap.count(c) == 0) {
                return false;
            }

            hashMap[c]--;
            if(hashMap[c] == 0) {
                hashMap.erase(c);
            }
        }

        return true;
    }
};