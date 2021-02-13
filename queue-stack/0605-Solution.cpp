// 01 矩阵
// https://leetcode-cn.com/leetbook/read/queue-stack/g7pyt/

#include <vector>
#include <queue>
#include <cassert>

using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<bool>> visited;
    int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool inArea(int x, int y) {
        return (x >= 0) && (x < m) && (y >= 0) && (y < n);
    }

    void bfs(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    q.emplace(make_pair(i, j));
                    visited[i][j] = true;
                }
            }
        }

        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto[curX, curY] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++) {
                    int newX = curX + direction[d][0];
                    int newY = curY + direction[d][1];

                    if(inArea(newX, newY) && !visited[newX][newY] && matrix[newX][newY] != 0) {
                        matrix[newX][newY] = matrix[curX][curY] + 1;
                        visited[newX][newY] = true;
                        q.emplace(make_pair(newX, newY));
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        assert(m > 0);
        n = matrix[0].size();

        visited.assign(m, vector<bool>(n, false));

        bfs(matrix);

        return matrix;
    }
};