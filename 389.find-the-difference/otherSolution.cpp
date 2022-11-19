#include <string>
#include <unordered_map>

class Solution1 {
public:
    char findTheDifference(std::string s, std::string t) {
        std::unordered_map<char, int> trace;
        char res;
        for(char i : s) {
            ++trace[i];
        }
        for(char i : t) {
            --trace[i];
            if(trace[i] < 0) {
                res = i;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    char findTheDifference(std::string s, std::string t) {
        char res = 0;
        for(char i : t) {
            res += i;
        }
        for(char i : s) {
            res -=i;
        }
        return res;
    }
};

class Solution3 {
public:
    char findTheDifference(std::string s, std::string t) {
        char res = 0;
        for(char i : t) {
            res ^= i;
        }
        for(char i : s) {
            res ^= i;
        }
        return res;
    }
};