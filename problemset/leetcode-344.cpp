// 344. 反转字符串
// https://leetcode-cn.com/problems/reverse-string/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;

        while(l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};