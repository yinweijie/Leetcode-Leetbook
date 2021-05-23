// 48. 旋转图像
// https://leetcode-cn.com/problems/rotate-image/

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        // [i, j] ==> 
        // [j, N-1-i] ==> 
        // [N-1-i, N-1-j] ==> 
        // [N-1-j, N-1-(N-1-i)] == [N-1-j, i]

        for(int i = 0; i < N / 2; i++) {
            for(int j = i; j < N - 1 - i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[N-1-j][i];
                matrix[N-1-j][i] = matrix[N-1-i][N-1-j];
                matrix[N-1-i][N-1-j] = matrix[j][N-1-i];
                matrix[j][N-1-i] = tmp;
            }
        }
    }
};