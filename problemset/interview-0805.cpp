// 面试题 08.05. 递归乘法
// https://leetcode-cn.com/problems/recursive-mulitply-lcci/

#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> memo;

public:
    int multiply(int A, int B) {
        if(B == 0) return 0;

        if(memo.count(B) > 0) return memo[B];

        if(B % 2 == 0) {
            memo[B] = multiply(A, B >> 1) + multiply(A, B >> 1);
            return memo[B];
        } else {
            memo[B] = A + multiply(A, B - 1);
            return memo[B];
        }
    }
};