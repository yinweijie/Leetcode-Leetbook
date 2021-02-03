// 打开转盘锁
// https://leetcode-cn.com/leetbook/read/queue-stack/kj48j/

#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

class Solution {
private:
    string shiftUp(string code, int index) {
        if(code[index] == '9') {
            code[index] = '0';
            return code;
        }

        code[index] += 1;
        return code;
    }

    string shiftDown(string code, int index) {
        if(code[index] == '0') {
            code[index] = '9';
            return code;
        }

        code[index] -= 1;
        return code;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        set<string> visited;
        set<string> deadCode(deadends.begin(), deadends.end());

        q.emplace("0000");
        visited.insert("0000");

        if(deadCode.find(q.front()) != deadCode.end()) {
            return -1;
        }

        int step = 0;
        while(!q.empty()) {
            int sz = q.size();
            // 这一层循环是必须的，每一个step都对应最多8种可能性，遍历这些可能性才算完成一个step
            for(int n = 0; n < sz; n++) {
                string curCode = q.front();
                q.pop();

                if(curCode == target) {
                    return step;
                }

                for(int i = 0; i < 4; i++) {
                    string upCode = shiftUp(curCode, i);
                    string downCode = shiftDown(curCode, i);

                    if(visited.find(upCode) == visited.end() 
                            && deadCode.find(upCode) == deadCode.end()) {
                        visited.insert(upCode);
                        q.emplace(upCode);
                    }
                    if(visited.find(downCode) == visited.end()
                            && deadCode.find(downCode) == deadCode.end()) {
                        visited.insert(downCode);
                        q.emplace(downCode);
                    }
                }
            }

            step++;
        }

        return -1;
    }
};