// 单词的唯一缩写
// https://leetcode-cn.com/leetbook/read/hash-table/xxd1mj/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> hashMap;

    string abbrev(const string& word) {
        int len = word.length();
        string res;

        if(len <= 2) {
            res = word;
        } else {
            res = word[0] + to_string(len - 2) + word[len - 1];
        }

        return res;
    }

public:
    ValidWordAbbr(vector<string>& dictionary) {
        for(const auto& str : dictionary) {
            hashMap[abbrev(str)].insert(str);
        }
    }
    
    bool isUnique(string word) {
        if(hashMap.find(abbrev(word)) == hashMap.end()) {
            return true;
        } else {
            return hashMap[abbrev(word)].count(word) > 0 && hashMap[abbrev(word)].size() == 1;
        }

        return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */