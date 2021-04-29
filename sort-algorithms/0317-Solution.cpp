// 面试题 10.01. 合并排序的数组
// https://leetcode-cn.com/leetbook/read/sort-algorithms/osomav/

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> ACpy = A;

        int i = 0, j = 0;
        for(int k = 0; k < m + n; k++) {
            if(i >= m) {
                A[k] = B[j];
                j++;
            } else if(j >= n) {
                A[k] = ACpy[i];
                i++;
            } else {
                if(ACpy[i] > B[j]) {
                    A[k] = B[j];
                    j++;
                } else {
                    A[k] = ACpy[i];
                    i++;
                }
            }
        }
    }
};

int main() {
    vector<int> A{1,2,3,0,0,0};
    int m = 3;
    vector<int> B{2,5,6};
    int n = 3;
    Solution().merge(A, m, B, n);
    return 0;
}