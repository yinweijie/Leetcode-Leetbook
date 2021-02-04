// 每日温度
// https://leetcode-cn.com/leetbook/read/queue-stack/genw3/

#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk;
        vector<int> res(T.size(), 0);

        for(int day = 0; day < T.size(); day++) {
            // if(stk.empty() || T[day] <= T[stk.top()]) {
            //     stk.emplace(day);
            // }

            while(!stk.empty() && T[day] > T[stk.top()]) {
                res[stk.top()] = day - stk.top();
                stk.pop();
            }

            stk.emplace(day);
        }

        return res;
    }
};