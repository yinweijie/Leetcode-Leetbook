// 旋转矩阵
// https://leetcode-cn.com/leetbook/read/array-and-string/clpgd/

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // (i,j) => (j,n-1-i) 即i行j列变成了j行倒数第i列
        // (j,n-1-i) => (n-1-i,n-1-j)
        // (n-1-i,n-1-j) => (n-1-j,n-1-(n-1-i)) == (n-1-j,i)
        for(int i = 0; i < n / 2; i++) {
            // 这里应该是j<n-1-i，而不是n-i，比如对于第0行，n-1位置处于顶角处，已经和(0,0)交换过一次了
            for(int j = i; j < n - 1 - i; j++) { 
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};