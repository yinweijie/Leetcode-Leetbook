// 四数相加 II
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/xheops/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> recordAB;
        for(int numA : A) {
            for(int numB : B) {
                recordAB[numA + numB]++;
            }
        }

        int res = 0;
        for(int numC : C) {
            for(int numD : D) {
                if(recordAB.find(-(numC + numD)) != recordAB.end()) {
                    res += recordAB[-(numC + numD)];
                }
            }
        }

        return res;
    }
};