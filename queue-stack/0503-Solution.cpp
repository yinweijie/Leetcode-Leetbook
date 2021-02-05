// 岛屿数量
// https://leetcode-cn.com/leetbook/read/queue-stack/gpfm5/

#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    vector<vector<bool>> visited;
    int m, n;
    int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool inArea(int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        visited[x][y] = true;

        for(int i = 0; i < 4; i++) {
            int newX = x + direction[i][0];
            int newY = y + direction[i][1];

            if(inArea(newX, newY) && grid[newX][newY] == '1' && !visited[newX][newY]) {
                dfs(grid, newX, newY);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        assert(m > 0);
        n = grid[0].size();

        int res = 0;
        visited.assign(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }
};