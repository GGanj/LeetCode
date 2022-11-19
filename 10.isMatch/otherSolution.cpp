#include <string>

class Solution1 {
public:
    bool isMatch(std::string s, std::string p) {
        return isSubMatch(s, 0, p, 0);
    }

    bool isSubMatch(std::string& s, int indexS, std::string& p, int indexP) {
        if(indexS < s.length() && indexP == p.length()) {
            return false;
        }
        if(indexS == s.length()) {
            if(indexP == p.length()) {
                return true;
            }
            if((p.length() - indexP) % 2 == 1) {
                 return false;
            }
            if(p[indexP + 1] == '*') {
                return isSubMatch(s, indexS, p, indexP + 2);
            } else {
                return false;
            }
        }

        if(s[indexS] == p[indexP] || p[indexP] == '.') {
            if((p.length() - indexP) > 1 && p[indexP + 1] == '*') {
                return isSubMatch(s, indexS + 1, p, indexP) || isSubMatch(s, indexS, p, indexP + 2);
            }
            return isSubMatch(s, indexS + 1, p, indexP + 1);
        }

        if(s[indexS] != p[indexP]) {
            if((p.length() - indexP) > 1 && p[indexP + 1] == '*') {
                return isSubMatch(s, indexS, p, indexP + 2);
            }
        }

        return false;
    }
};