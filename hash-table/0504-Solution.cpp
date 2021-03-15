// 有效的数独
// https://leetcode-cn.com/leetbook/read/hash-table/xxpit5/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int boxIndex(int row, int col) {
        return (row / 3 * 3) + (col / 3);
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //                  <num, count>
        vector<unordered_map<int, int>> boxMap(9);
        vector<unordered_map<int, int>> rowMap(9);
        vector<unordered_map<int, int>> colMap(9);

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == '.') continue;

                int boxCount = ++boxMap[boxIndex(i, j)][board[i][j]];
                int rowCount = ++rowMap[i][board[i][j]];
                int colCount = ++colMap[j][board[i][j]];
                
                if(boxCount > 1 || rowCount > 1 || colCount > 1) {
                    return false;
                }
            }
        }

        return true;
    }
};