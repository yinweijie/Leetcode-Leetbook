// 杨辉三角
// https://leetcode-cn.com/leetbook/read/array-and-string/cuj3m/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++) {
            vector<int> row(i + 1);
            row[0] = 1;
            for(int j = 1; j < i; j++) {
                int e = res[i - 1][j - 1] + res[i - 1][j];
                row[j] = e;
            }
            row[i] = 1;
            res.emplace_back(std::move(row));
        }

        return res;
    }
};

int main() {
    Solution().generate(5);
    return 0;
}