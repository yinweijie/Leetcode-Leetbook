// 快乐数
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/fqqcs/

#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> treeSet;
        treeSet.insert(n);

        while(n != 1) {
            int sqrSum = 0;
            while(n != 0) {
                sqrSum += (n % 10) * (n % 10);
                n /= 10;
            }

            if(treeSet.find(sqrSum) != treeSet.end()) {
                return false;
            }

            treeSet.insert(sqrSum);
            n = sqrSum;
        }

        return true;
    }
};