// 稀疏矩阵的乘法
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x77ydg/

#include <vector>

using namespace std;

class Solution {
private:
    int product(int row, int col) {
        int sz = (*mat1Ptr)[row].size();

        int res = 0;
        for(int i = 0; i < sz; i++) {
            res += (*mat1Ptr)[row][i] * (*mat2Ptr)[i][col];
        }

        return res;
    }

    vector<vector<int>>* mat1Ptr;
    vector<vector<int>>* mat2Ptr;
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        mat1Ptr = &mat1;
        mat2Ptr = &mat2;
        vector<vector<int>> res(mat1.size());

        for(int i = 0; i < mat1.size(); i++) {
            for(int j = 0; j < mat2[0].size(); j++) {
                res[i].emplace_back(product(i, j));
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> mat1 {{1,0,0},{-1,0,3}};
    vector<vector<int>> mat2 {{7,0,0},{0,0,0},{0,0,1}};

    Solution().multiply(mat1, mat2);
    return 0;
}