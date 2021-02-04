// 完全平方数
// https://leetcode-cn.com/leetbook/read/queue-stack/kfgtt/

#include <queue>
#include <vector

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<bool> visited(n + 1, false);

        q.emplace(n);
        visited[n] = true;

        int step = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int n = 0; n < sz; n++) {
                int num = q.front();
                q.pop();

                if(num == 0) {
                    return step;
                }

                for(int i = 1; num - i*i >= 0; i++) {
                    if(!visited[num - i*i]) {
                        q.emplace(num - i*i);
                        visited[num - i*i] = true;
                    }
                }
            }
            step++;
        }

        return -1;
    }
};