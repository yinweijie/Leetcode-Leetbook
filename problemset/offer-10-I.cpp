// 剑指 Offer 10- I. 斐波那契数列
// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/

#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo;

    int fibR(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        if(memo[n] != 0) return memo[n];

        memo[n] = fibR(n - 1) % 1000000007 + fibR(n - 2) % 1000000007;

        return memo[n];
    }

public:
    int fib(int n) {
        memo.resize(n + 1);
        return fibR(n) % 1000000007;
    }
};