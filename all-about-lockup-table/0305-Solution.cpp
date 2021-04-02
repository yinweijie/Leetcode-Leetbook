// 同构字符串
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/f1f86/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    bool check(const string& s, const string& t) {
        unordered_map<char, char> hashMap;

        for(int i = 0; i < s.length(); i++) {
            if(hashMap.find(s[i]) != hashMap.end()) {
                if(hashMap[s[i]] != t[i]) {
                    return false;
                }
            } else {
                hashMap[s[i]] = t[i];
            }
        }

        return true;
    }

public:
    bool isIsomorphic(string s, string t) {
        return check(s, t) && check(t, s);
    }
};