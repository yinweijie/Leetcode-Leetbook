// 零矩阵
// https://leetcode-cn.com/leetbook/read/array-and-string/ciekh/

#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int, int>> zeros;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    zeros.emplace_back(make_pair(i, j));
                }
            }
        }
        for(auto[i, j] : zeros) {
            for(int jj = 0; jj < n; jj++) {
                matrix[i][jj] = 0;
            }
            for(int ii = 0; ii < m; ii++) {
                matrix[ii][j] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    Solution().setZeroes(matrix);
    return 0;
}