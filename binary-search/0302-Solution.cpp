// x 的平方根
// https://leetcode-cn.com/leetbook/read/binary-search/xe9cog/

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        int res = 0;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if((long long)mid * mid == x) return mid;

            if((long long)mid * mid > x) {
                r = mid - 1;
            } else {
                res = mid;
                l = mid + 1;
            }
        }

        return res;
    }
};