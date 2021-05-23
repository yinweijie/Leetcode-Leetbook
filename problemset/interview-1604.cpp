// 面试题 16.04. 井字游戏
// https://leetcode-cn.com/problems/tic-tac-toe-lcci/

#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
public:
    string tictactoe(vector<string>& board) {
        int N = board.size();
        vector<unordered_map<char, int>> row(N);
        vector<unordered_map<char, int>> col(N);
        unordered_map<char, int> diag1;
        unordered_map<char, int> diag2;
        unordered_map<char, int> blank;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] == ' ') {
                    blank[board[i][j]]++;
                    continue;
                }

                row[i][board[i][j]]++;
                col[j][board[i][j]]++;
                if(i == j) diag1[board[i][j]]++;
                if(i + j == (N - 1)) diag2[board[i][j]]++;
            }
        }

        for(int i = 0; i < N; i++) {
            if(row[i].size() == 1) {
                if(row[i].count('O') > 0 && row[i]['O'] == N) return "O";
                if(row[i].count('X') > 0 && row[i]['X'] == N) return "X";
            }

            if(col[i].size() == 1) {
                if(col[i].count('O') > 0 && col[i]['O'] == N) return "O";
                if(col[i].count('X') > 0 && col[i]['X'] == N) return "X";
            }
        }

        if(diag1.size() == 1) {
            if(diag1.count('O') > 0 && diag1['O'] == N) return "O";
            if(diag1.count('X') > 0 && diag1['X'] == N) return "X";
        }
        if(diag2.size() == 1) {
            if(diag2.count('O') > 0 && diag2['O'] == N) return "O";
            if(diag2.count('X') > 0 && diag2['X'] == N) return "X";
        }

        if(blank.size() == 0) {
            return "Draw";
        } else {
            return "Pending";
        }
    }
};