// 日志速率限制器
// https://leetcode-cn.com/leetbook/read/hash-table/xx91k3/

#include <string>
#include <unordered_map>

using namespace std;

class Logger {
private:
    unordered_map<string, int> hashMap;

public:
    /** Initialize your data structure here. */
    Logger() {

    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(hashMap.find(message) == hashMap.end()) {
            hashMap[message] = timestamp;
            return true;
        } else {
            if(timestamp < hashMap[message] + 10) {
                return false;
            } else {
                hashMap[message] = timestamp;
                return true;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */