// 杨辉三角 II
// https://leetcode-cn.com/leetbook/read/array-and-string/ctyt1/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre, cur;
        for(int i = 0; i <= rowIndex; i++) {
            cur.resize(i + 1);
            cur[0] = 1;
            for(int j = 1; j < i; j++) {
                cur[j] = pre[j - 1] + pre[j];
            }
            cur[i] = 1;
            
            // pre = cur;
            pre.swap(cur); // 交换指针
        }

        return pre;
    }
};

int main() {
    Solution().getRow(3);
    return 0;
}