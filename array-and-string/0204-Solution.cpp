// 对角线遍历
// https://leetcode-cn.com/leetbook/read/array-and-string/cuxq3/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();

        if(m == 0) return res;

        int n = matrix[0].size();
        bool direction = true;

        int digaSum = (m - 1) + (n - 1);
        for(int d = 0; d <= digaSum; d++) {
            if(direction) { // i = d, j = 0
                int i = d > (m - 1) ? (m - 1) : d;
                int j = d - i;
                for(; i >= 0 && i < m && j >= 0 && j < n; i--, j++) {
                    res.emplace_back(matrix[i][j]);
                }
                direction = false;
            } else { // i = 0, j = d
                int j = d > (n - 1) ? (n - 1) : d;
                int i = d - j;
                for(; i >= 0 && i < m && j >= 0 && j < n; i++, j--) {
                    res.emplace_back(matrix[i][j]);
                }
                direction = true;
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution().findDiagonalOrder(matrix);
    return 0;
}