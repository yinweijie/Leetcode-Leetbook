// 第一个错误的版本
// https://leetcode-cn.com/leetbook/read/binary-search/xepthr/

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // [l, r]
        int l = 1, r = n;

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(isBadVersion(mid)) {
                r = mid; // mid是bad version，因此需要被包含在寻找集合中继续寻找
            } else {
                l = mid + 1; // mid不是bad version，因此可以排除在外
            }
        }

        return l;
    }
};