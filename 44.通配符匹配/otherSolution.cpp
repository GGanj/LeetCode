#include <string>
#include <iostream>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        return subMatch(s, 0, p, 0);
    }

    bool subMatch(std::string s, int indexS, std::string p, int indexP) {
        if(indexP == p.size()) {
            return indexS == s.size();
        }
        bool isOverFlow = indexS < s.size();
        if(p[indexP] == '*') {
            return (isOverFlow && subMatch(s, indexS + 1, p, indexP)) || (isOverFlow && subMatch(s, indexS + 1, p, indexP + 1)) || subMatch(s, indexS, p, indexP + 1);
        }

        bool match = isOverFlow && (s[indexS] == p[indexP] || p[indexP] == '?');
        return match && subMatch(s, indexS + 1, p, indexP + 1);
    }
};