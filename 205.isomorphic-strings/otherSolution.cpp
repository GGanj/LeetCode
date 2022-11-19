#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if(s.size() != t.size()) {
            return false;
        }
        std::unordered_map<char, char> trace1, trace2;
        for(int i = 0; i < s.size(); ++i) {
            if(trace1[s[i]]) {
                if(t[i] != trace1[s[i]]) {
                    return false;
                }
            } else {
                if(trace2.find(t[i]) != trace2.end()) {
                    return false;
                }
                trace1[s[i]] = t[i];
                trace2[t[i]] = s[i];
            }
        }
        return true;
    }
};