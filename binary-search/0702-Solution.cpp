// 有效的完全平方数
// https://leetcode-cn.com/leetbook/read/binary-search/xel3tc/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0, r = num;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if((long long)mid * mid == num) {
                return true;
            }

            if((long long)mid * mid > num) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false;
    }
};