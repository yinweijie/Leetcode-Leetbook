// 面试题 10.01. 合并排序的数组
// https://leetcode-cn.com/problems/sorted-merge-lcci/

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> tmp(m + n);

        int i = 0, j = 0;
        for(int k = 0; k < tmp.size(); k++) {
            if(i == m || j == n) {
                if(i == m) {
                    tmp[k] = B[j++];
                } else {
                    tmp[k] = A[i++];
                }
            } else {
                if(A[i] < B[j]) {
                    tmp[k] = A[i++];
                } else {
                    tmp[k] = B[j++];
                }
            }
        }

        A = std::move(tmp);
    }
};

int main() {
    vector<int> A {1,2,3,0,0,0};
    int m = 3;
    vector<int> B {2,5,6};
    int n = 3;

    Solution().merge(A, m, B, n);
    return 0;
}