// 快乐数
// https://leetcode-cn.com/leetbook/read/hash-table-plus/zz4yv/

#include <unordered_set>

using namespace std;

class Solution {
private:
    int calSqrSum(int num) {
        int sum = 0;

        while(num != 0) {
            sum += (num % 10) * (num % 10);
            num /= 10;
        }

        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> hashSet;
        hashSet.emplace(n);

        while(n != 1) {
            n = calSqrSum(n);
            if(hashSet.count(n) > 0) {
                return false;
            }

            hashSet.emplace(n);
        }

        return true;
    }
};

int main() {
    Solution().isHappy(19);
    return 0;
}