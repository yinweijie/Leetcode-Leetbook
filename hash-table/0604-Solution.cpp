// 四数相加 II
// https://leetcode-cn.com/leetbook/read/hash-table/xxwhng/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sumAB;
        int res = 0;

        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                sumAB[A[i] + B[j]]++;
            }
        }

        for(int i = 0; i < C.size(); i++) {
            for(int j = 0; j < D.size(); j++) {
                if(sumAB.find(-(C[i] + D[j])) != sumAB.end()) {
                    res += sumAB[-(C[i] + D[j])];
                }
            }
        }

        return res;
    }
};