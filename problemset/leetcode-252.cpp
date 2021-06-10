// 252. 会议室
// https://leetcode-cn.com/problems/meeting-rooms/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i - 1][1] > intervals[i][0]) {
                return false;
            }
        }

        return true;
    }
};