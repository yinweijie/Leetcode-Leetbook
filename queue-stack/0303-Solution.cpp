// 墙与门
// https://leetcode-cn.com/leetbook/read/queue-stack/kcf6g/

#include <vector>
#include <queue>
#include <cassert>

using namespace std;

class Solution {
private:
    int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int m, n;
    const int GATE = 0;
    const int EMPTY = 2147483647;

    bool inArea(int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    void bfs(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, false));
        
        // 把for循环放在bfs里，如果在wallsAndGates里用for循环反复调用bfs，会超时

        // 并且，for循环放在bfs里，思路也有些不同了，由于GATE被首先放入queue中，因此
        // 会先遍历第一个GATE周围的第一层空白区，然后遍历第二个GATE周围的第一层空白区...
        // 当GATE都出队后，才开始处理第一层空白区，并开始入队第二层空白区，所以哪个GATE
        // 先碰到空白区，这个空白区就属于谁
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rooms[i][j] == GATE) {
                    q.emplace(make_pair(i, j));
                    visited[i][j] = true;
                }
            }
        }

        while(!q.empty()) {
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int newX = curX + direction[i][0];
                int newY = curY + direction[i][1];

                if(inArea(newX, newY) && !visited[newX][newY] && rooms[newX][newY] == EMPTY) {
                    visited[newX][newY] = true;
                    q.emplace(make_pair(newX, newY));
                    rooms[newX][newY] = rooms[curX][curY] + 1;
                }
            }
        }
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        m = rooms.size();
        assert(m > 0);
        n = rooms[0].size();

        bfs(rooms);
    }
};

/*
** BFS Template
**
int BFS(Node root, Node target) {
    Queue<Node> queue;  // store all nodes which are waiting to be processed
    Set<Node> used;     // store all the used nodes
    int step = 0;       // number of steps neeeded from root to current node
    // initialize
    add root to queue;
    add root to used;
    // BFS
    while (queue is not empty) {
        step = step + 1;
        // iterate the nodes which are already in the queue
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Node cur = the first node in queue;
            return step if cur is target;
            for (Node next : the neighbors of cur) {
                if (next is not in used) {
                    add next to queue;
                    add next to used;
                }
            }
            remove the first node from queue;
        }
    }
    return -1;          // there is no path from root to target
}
*/