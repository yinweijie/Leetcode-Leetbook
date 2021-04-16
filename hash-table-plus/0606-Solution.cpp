// 单词的唯一缩写
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x7q2oh/

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> hashMap;

    string abbr(const string& str) {
        string strMid = str.size() - 2 > 0 ? to_string(str.size() - 2) : "";
        return str.front() + strMid + str.back();
    }

public:
    ValidWordAbbr(vector<string>& dictionary) {
        for(auto str : dictionary) {
            hashMap[abbr(str)].emplace(str);
        }
    }
    
    bool isUnique(string word) {
        string abbrStr = abbr(word);

        if(hashMap.count(abbrStr) == 0) {
            return true;
        } else {
            if(hashMap[abbrStr].count(word) != 0 && hashMap[abbrStr].size() == 1) {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */

int main() {
    vector<string> dic {"deer", "door"};
    ValidWordAbbr obj(dic);
    obj.isUnique("dear");
    return 0;
}