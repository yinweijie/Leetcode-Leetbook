// 面试题 01.05. 一次编辑
// https://leetcode-cn.com/problems/one-away-lcci/

#include <string>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int firstSize = first.size();
        int secondSize = second.size();

        if(firstSize == secondSize) { // 可能被修改
            int diffCnt = 0;

            for(int i = 0; i < firstSize; i++) {
                if(first[i] != second[i]) {
                    diffCnt++;
                    if(diffCnt > 1) return false;
                }
            }
        } else if(abs(firstSize - secondSize) == 1) { // 可能被删除或添加一个字符
            if(firstSize < secondSize) swap(first, second);

            int i = 0, j = 0;
            int diffCnt = 0;
            while(true) {
                if(i >= firstSize && j >= secondSize) break;

                if(first[i] == second[j]) {
                    i++;
                    j++;
                } else {
                    diffCnt++;
                    i++;

                    if(diffCnt > 1) return false;
                }
            }
        } else {
            return false;
        }

        return true;
    }
};