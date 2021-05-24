// 54. 螺旋矩阵
// https://leetcode-cn.com/problems/spiral-matrix/

#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    // 右、下、左、上
    int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    bool inArea(int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int m;
    int n;

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        assert(m > 0);
        n = matrix[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int posX = 0;
        int posY = 0;
        visited[posX][posY] = true;
        int iDirection = 0;
        vector<int> res;

        res.emplace_back(matrix[posX][posY]);
        while(true) {
            int newPosX = posX + direction[iDirection][0];
            int newPosY = posY + direction[iDirection][1];
            int cnt = 0;

            // 变更方向
            while(!inArea(newPosX, newPosY) || visited[newPosX][newPosY]) {
                if(cnt >= 3) return res;

                iDirection = (iDirection + 1) % 4;
                newPosX = posX + direction[iDirection][0];
                newPosY = posY + direction[iDirection][1];

                cnt++;
            }

            posX = newPosX;
            posY = newPosY;
            visited[posX][posY] = true;
            res.emplace_back(matrix[posX][posY]);
        }

        return res;
    }
};

int main() {
    vector<vector<int>> matrix {{1,2,3},{4,5,6},{7,8,9}};
    Solution().spiralOrder(matrix);
    return 0;
}