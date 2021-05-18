// 1108. IP 地址无效化
// https://leetcode-cn.com/problems/defanging-an-ip-address/

#include <string>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for(char c : address) {
            if(c == '.') {
                res += "[.]";
            } else {
                res += c;
            }
        }

        return res;
    }
};