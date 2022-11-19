#include <string>
#include <unordered_map>

class Solution1 {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> trace;
        for(char i : s) {
            ++trace[i];
        }
        for(int i = 0; i < s.size(); ++i) {
            if(trace[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};