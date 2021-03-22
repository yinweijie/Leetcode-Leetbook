// Pow(x, n)
// https://leetcode-cn.com/leetbook/read/binary-search/xe7k32/

class Solution {
private:
    double powRecursive(double x, long long n) {
        if(n == 0) return 1.0;

        double resSqrt = powRecursive(x, n / 2);
        if(n % 2 == 0) {
            return resSqrt * resSqrt;
        } else {
            return resSqrt * resSqrt * x;
        }
    }

public:
    double myPow(double x, long long n) {
        if(n >= 0) {
            return powRecursive(x, n);
        } else {
            return 1.0 / powRecursive(x, -n);
        }
    }
};