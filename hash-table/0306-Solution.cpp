// 快乐数
// https://leetcode-cn.com/leetbook/read/hash-table/xh1k9i/

#include <unordered_set>

using namespace std;

class Solution {
private:
    int calDigitSquareSum(int n) {
        int sum = 0;

        while(n) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }

        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> hashSet;
        int sum = 0;

        while(true) {
            sum = calDigitSquareSum(n);

            if(sum == 1) break;

            if(hashSet.count(sum) > 0) {
                return false;
            }
            hashSet.insert(sum);

            n = sum;
        }

        return true;
    }
};