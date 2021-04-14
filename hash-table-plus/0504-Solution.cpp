// 有效的数独
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x70xli/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int boxIndex(int i, int j) {
        int boxRow = i / 3;
        int boxCol = j / 3;

        return 3 * boxRow + boxCol;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowFlag(9);
        vector<unordered_set<char>> colFlag(9);
        vector<unordered_set<char>> boxFlag(9);

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == '.') continue;

                if(rowFlag[i].count(board[i][j]) > 0 ||
                        colFlag[j].count(board[i][j]) > 0 ||
                        boxFlag[boxIndex(i, j)].count(board[i][j]) > 0) {
                    return false;
                }

                rowFlag[i].emplace(board[i][j]);
                colFlag[j].emplace(board[i][j]);
                boxFlag[boxIndex(i, j)].emplace(board[i][j]);
            }
        }

        return true;
    }
};