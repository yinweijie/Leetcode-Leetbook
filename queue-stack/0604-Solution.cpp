// 图像渲染
// https://leetcode-cn.com/leetbook/read/queue-stack/g02cj/

#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
private:
    int oldColor;
    int m, n;
    vector<vector<bool>> visited;
    int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool inArea(int x, int y) {
        return (x >= 0) && (x < m) && (y >= 0) && (y < n);
    }

    void dfs(vector<vector<int>>& image, int x, int y, int color) {
        visited[x][y] = true;
        image[x][y] = color;

        for(int i = 0; i < 4; i++) {
            int newX = x + direction[i][0];
            int newY = y + direction[i][1];

            if(inArea(newX, newY) && !visited[newX][newY] && image[newX][newY] == oldColor) {
                dfs(image, newX, newY, color);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        oldColor = image[sr][sc];
        m = image.size();
        assert(m > 0);
        n = image[0].size();

        visited.assign(m, vector<bool>(n, false));
        dfs(image, sr, sc, newColor);

        return image;
    }
};