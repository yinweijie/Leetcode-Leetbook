// 面试题 01.08. 零矩阵
// https://leetcode-cn.com/problems/zero-matrix-lcci/

#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    void setRow(vector<vector<int>>& matrix, int row) {
        int m = matrix.size();
        assert(m > 0);
        int n = matrix[0].size();

        for(int j = 0; j < n; j++) {
            if(visited[row][j] || matrix[row][j] == 0) continue;

            visited[row][j] = true;
            matrix[row][j] = 0;
        }
    }
    void setCol(vector<vector<int>>& matrix, int col) {
        int m = matrix.size();
        assert(m > 0);
        int n = matrix[0].size();

        for(int i = 0; i < m; i++) {
            if(visited[i][col] || matrix[i][col] == 0) continue;

            visited[i][col] = true;
            matrix[i][col] = 0;
        }
    }

    vector<vector<bool>> visited;

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        assert(m > 0);
        int n = matrix[0].size();

        visited.assign(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && matrix[i][j] == 0) {
                    visited[i][j] = true;
                    setRow(matrix, i);
                    setCol(matrix, j);
                }
            }
        }
    }
};