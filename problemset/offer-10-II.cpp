// 剑指 Offer 10- II. 青蛙跳台阶问题
// https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/

#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo;

    int numWaysR(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;

        if(memo[n] != 0) return memo[n];

        memo[n] = numWaysR(n - 1) % 1000000007 + numWaysR(n - 2) % 1000000007;

        return memo[n];
    }

public:
    int numWays(int n) {
        memo.resize(n + 1);
        return numWaysR(n) % 1000000007;
    }
};