// 岛屿数量
// https://leetcode-cn.com/leetbook/read/queue-stack/kbcqv/

#include <vector>
#include <cassert>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<bool>> visited;
    const char ISLAND = '1';
    int m, n;
    int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool inArea(int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    void bfs(vector<vector<char>>& grid, int x, int y) {
        queue<pair<int, int>> q;
        q.emplace(make_pair(x, y));
        visited[x][y] = true;

        while(!q.empty()) {
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int newX = curX + direction[i][0];
                int newY = curY + direction[i][1];

                if(inArea(newX, newY) && !visited[newX][newY] && grid[newX][newY] == ISLAND) {
                    visited[newX][newY] = true;
                    q.emplace(make_pair(newX, newY));
                }
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
                if(grid[i][j] == ISLAND && !visited[i][j]) {
                    res++;
                    bfs(grid, i, j);
                }
            }
        }

        return res;
    }
};