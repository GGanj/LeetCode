#include <string>
#include <unordered_map>

class Solution1 {
public:
    bool isAnagram(std::string s, std::string t) {
        if(s.size() != t.size()) {
            return false;
        }
        std::unordered_map<int, int> counts1, counts2;
        for(int i = 0; i < s.size(); ++i) {
            ++counts1[s[i]];
            ++counts2[t[i]];
        }
        return counts1 == counts2;
    }
};

class Solution2 {
public:
    bool isAnagram(std::string s, std::string t) {
        if(s.size() != t.size()) {
            return false;
        }
        std::unordered_map<int, int> counts;
        for(int i = 0; i < s.size(); ++i) {
            ++counts[s[i]];
            --counts[t[i]];
            if(counts[s[i]] == 0) {
                counts.erase(s[i]);
            }
            if(counts[t[i]] == 0) {
                counts.erase(t[i]);
            }
        }
        return !counts.size();
    }
};