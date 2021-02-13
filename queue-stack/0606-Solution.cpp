// 钥匙和房间
// https://leetcode-cn.com/leetbook/read/queue-stack/gle1r/

#include <vector>

using namespace std;

class Solution {
private:
    vector<bool> visited;
    int count = 0;

    void dfs(vector<vector<int>>& rooms, int index) {
        visited[index] = true;
        count++;

        for(int i : rooms[index]) {
            if(!visited[i]) {
                dfs(rooms, i);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        visited.assign(n, false);

        dfs(rooms, 0);

        return (count == n);
    }
};