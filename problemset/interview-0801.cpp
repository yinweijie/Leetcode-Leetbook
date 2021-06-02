// 面试题 08.01. 三步问题
// https://leetcode-cn.com/problems/three-steps-problem-lcci/

#include <vector>

using namespace std;

class Solution {
private:
    vector<long long> memo;

    long long waysToStepR(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 4;

        if(memo[n] != 0) return memo[n];

        memo[n] = (long long)waysToStepR(n - 1) % 1000000007 
            + (long long)waysToStepR(n - 2) % 1000000007 
            + (long long)waysToStepR(n - 3) % 1000000007;

        return memo[n];
    }

public:
    int waysToStep(int n) {
        memo.resize(n + 1);
        return waysToStepR(n) % 1000000007;
    }
};

int main() {
    Solution().waysToStep(61);
    return 0;
}