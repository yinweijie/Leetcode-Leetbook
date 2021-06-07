// 剑指 Offer 16. 数值的整数次方
// https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/

class Solution {
private:
    double myPowR(double x, long long n) {
        if(n == 0) return 1;

        if(n < 0) {
            return 1.0 / (x * myPowR(x, -(n + 1)));
        }

        if(n % 2 == 0) {
            return myPowR(x*x, n / 2);
        } else {
            return x * myPowR(x, n - 1);
        }
    }

public:
    double myPow(double x, int n) {
        // double res;

        // if(n >= 0) {
        //     res = myPowR(x, n);
        // } else {
        //     res = 1.0 / myPowR(x, -n));
        // }

        return myPowR(x, n);
    }
};