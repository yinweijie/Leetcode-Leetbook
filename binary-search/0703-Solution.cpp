// 寻找比目标字母大的最小字母
// https://leetcode-cn.com/leetbook/read/binary-search/xeiuui/

#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size();

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(letters[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        if(l == letters.size()) return letters[0];

        return letters[l];
    }
};